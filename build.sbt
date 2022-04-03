ThisBuild / scalaVersion     := "2.13.7"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "com.github.merledu"

val chiselVersion = "3.5.0-RC2"

lazy val root = (project in file("."))
  .settings(
    name := "nucleusrv",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % "0.5.0-RC2" % "test"
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full),
  )
lazy val caravan = (project in file("caravan"))
lazy val jigsaw = (project in file("jigsaw")).dependsOn(caravan)
lazy val ccache = (project in file("ccache")).dependsOn(caravan, jigsaw)

dependsOn(caravan, jigsaw, ccache)