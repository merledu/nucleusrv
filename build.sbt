import sbt.Keys.javacOptions
// See README.md for license details.

def scalacOptionsVersion(scalaVersion: String): Seq[String] = {
  Seq() ++ {
    // If we're building with Scala > 2.11, enable the compile option
    //  switch to support our anonymous Bundle definitions:
    //  https://github.com/scala/bug/issues/10047
    CrossVersion.partialVersion(scalaVersion) match {
      case Some((2, scalaMajor: Long)) if scalaMajor < 12 => Seq()
      case _ => Seq("-Xsource:2.11")
    }
  }
}

def javacOptionsVersion(scalaVersion: String): Seq[String] = {
  Seq() ++ {
    // Scala 2.12 requires Java 8. We continue to generate
    //  Java 7 compatible code for Scala 2.11
    //  for compatibility with old clients.
    CrossVersion.partialVersion(scalaVersion) match {
      case Some((2, scalaMajor: Long)) if scalaMajor < 12 =>
        Seq("-source", "1.7", "-target", "1.7")
      case _ =>
        Seq("-source", "1.8", "-target", "1.8")
    }
  }
}

name := "nucleusrv"

version := "3.2.0"

scalaVersion := "2.12.10"

crossScalaVersions := Seq("2.12.10", "2.11.12")


resolvers ++= Seq(
  Resolver.sonatypeRepo("snapshots"),
  Resolver.sonatypeRepo("releases")
)

// Provide a managed dependency on X if -DXVersion="" is supplied on the command line.
val defaultVersions = Map(
  "chisel3" -> "3.5.5",
  "chisel-iotesters" -> "2.5.6"
  )

lazy val root = (project in file(".")).settings(
  libraryDependencies ++= Seq("chisel3","chisel-iotesters").map {
    dep: String => "edu.berkeley.cs" %% dep % sys.props.getOrElse(dep + "Version", defaultVersions(dep))
  } ++ Seq(
    "edu.berkeley.cs" %% "chiseltest" % "0.5.6" % "test",
    "org.scalatest" %% "scalatest" % "3.2.0" % "test"
  ),
  addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % defaultVersions("chisel3") cross CrossVersion.full),
  resolvers ++= Seq(
    Resolver.sonatypeRepo("snapshots"),
    Resolver.sonatypeRepo("releases")
  ),
  scalacOptions ++= scalacOptionsVersion(scalaVersion.value),
  javacOptions ++= javacOptionsVersion(scalaVersion.value)
)

logBuffered in Test := false

parallelExecution in Test := false



trapExit := false
