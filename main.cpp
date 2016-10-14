// #include <iostream>
// #include <cvc4/cvc4.h>
// using namespace CVC4;
// int main() {
//   ExprManager em;
//   Expr helloworld = em.mkVar("Hello World!", em.booleanType());
//   SmtEngine smt(&em);
//   std::cout << helloworld << " is " << smt.query(helloworld) << std::endl;
//   return 0;
// }
#include <iostream>
#include "AST.h"
#include "Parser.h"
#include <fstream>
using namespace mm;
int main(int argc, char **argv) {
//   Expr *Post = new BinaryExpr("<", new Var("b"), new IntConst(10), true);
//   Stmt *Prog = new AssignStmt(new Var("b"), 
// 			      new BinaryExpr("+", new Var("a"), new IntConst(1)));
//   auto *Result = Prog->WeakestPrecondition(Post);
//   Result->dump(std::cout);
  
  std::string test = "(1>3)";
  
  if (argc > 1) {
    std::ifstream ifs(argv[1]);
    test.assign( (std::istreambuf_iterator<char>(ifs) ),
                (std::istreambuf_iterator<char>()) );
  }
  
  Stream in(test.c_str(), 0, test.length()-1);
  Result R = ParseStmt(in);
  if (R.Ptr) {
    std::cout << "FINAL\n";
    R.getAs<Stmt>()->dump(std::cout);
  }
  
  Expr *Post = new BinaryExpr(">", new Var("y"), new IntConst(5), true);
  R.getAs<Stmt>()->WeakestPrecondition(Post)->dump(std::cout);
  
  
}