#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
 
   cout << "Usando sobrecarga e parametros default.\n\n";

   GradeBook gradebook0;
   GradeBook gradebook1( "Math" );
   const GradeBook GRADEBOOK2( "Physics", 2 );
   GradeBook gradebook3( "Geography", 10 );
   GradeBook gradebook4( 3 );
   const GradeBook GRADEBOOK5( GRADEBOOK2 );
   
   cout << "\nDuas versoes do metodo displayMessage: const e nao const\n";
   GRADEBOOK2.displayMessage( );
   GRADEBOOK5.displayMessage( );
   gradebook3.displayMessage( );//Objects não const podem usar métodos const

   //ERROR: tentando usar método não const
   //GRADEBOOK5.setNumAlunos( 10 );

   //Variável pertence a classe
   cout << "\nTestando atributos e metodos statics.\n";
   cout << "Alunos que conseguiram vaga na escola " << GradeBook::getnumAlunosEscola( ) << '\n';
   cout << "Numero de GradeBooks instanciados: " << GradeBook::getnumGradeBooks( ) << '\n';
   cout << "Numero de GradeBooks instanciados: " << gradebook0.getnumGradeBooks( ) << '\n';

   gradebook0.printListaAlunos( );

   cout << "\nUsando arrays. Fornecendo e imprimindo notas.\n";
   const int NGRADES = 5;
   double grandes[ NGRADES ] = { 10.0, 8.9, 9.3, 7.8, 6.6 };

   gradebook3.fornecerNotas( grandes, NGRADES );
   gradebook3.printGrades( );
   
   return 0;
}