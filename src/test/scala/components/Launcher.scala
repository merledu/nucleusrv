
// package components

// import chisel3.iotesters.{Driver, TesterOptionsManager}
// import utils.TutorialRunner
// import chisel3._

// object Launcher {
//   val tests = Map(
//     "cpu" -> {(manager: TesterOptionsManager)=>
//       Driver.execute(()=>new CPU(), manager){
//         (c)=>new RiscTest(c)
//       }
//     }
//   )
//   def main(args: Array[String]): Unit = {
//     TutorialRunner("tests", tests, args)
//   }
// }
