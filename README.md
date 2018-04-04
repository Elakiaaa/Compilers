1.Backpatching

              In this program backpatching performed on conditional statements.
              
              truelist,falselist,nextaddress of the code generated.
              
2.CFG construction
              
              In this program control flow graph was constructed after basic block construction
              
3.Constant propagation
             
             In this program optimization performed.
             
4.forwhile

          In this program forloop converted to whileloop.
          
5.ifelse

        If no else statements presented for If in program,it will add else statements.
        
6.lebeled Tree

        It will allocates labels for syntaxtree and generate codes.
        
 7.symboltable
 
         Creates symbol tabel for declaration of program.
         
         
         
         
 Steps for Compilation:
 
  lex filename.l
  
  yacc -d filename.y
  
  gcc/g++ lex.yy.c y.tab.c -ll -lfl
  
  ./a.out>inputname
