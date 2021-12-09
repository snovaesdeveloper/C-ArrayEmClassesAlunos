#include "GradeBook.h"

#include <iostream>
using std::cout;

//Instanciação de variáveis statics
int GradeBook::numGradeBooks = 0;
int GradeBook::numAlunosEscola = 0;
const int GradeBook::MAXNUMALUNOSESCOLA = 20;
string GradeBook::alunos[ NUMALUNOSMIN ] = {"Carlos Fernando", "Andreza Raphaela"};


GradeBook::GradeBook( )
:courseName(""), numAlunos( 0 ), MAXSIZENAME( 9 ), check( false )
{  
      numGradeBooks++;  
}

GradeBook::GradeBook( string name, int numAlunos )
:MAXSIZENAME( 9 ), check( false )
{
    setCourseName( name );
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( int numAlunos )
:courseName(""), MAXSIZENAME( 9 ), check( false )
{
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( const GradeBook& other )
:MAXSIZENAME( other.MAXSIZENAME ), check( other.check )
{
    this->courseName = other.courseName;
    setNumAlunos( other.numAlunos );

    numGradeBooks++;
}

/* GradeBook::GradeBook( const GradeBook& other )
:courseName( other.courseName ), numAlunos( other.numAlunos ), check( other.check )
{
    numGradeBooks++;
}
} */

 void GradeBook::setCourseName( string name )
{
    if ( name.length( ) <= MAXSIZENAME )
        courseName = name;
    else   
        {
            courseName = name.substr( 0, MAXSIZENAME );
            cout << "Nome alterado. Excedeu o valor maximo. \n";
        }
}


void GradeBook::setNumAlunos( int numAlunos )
{
    cout << "Numero de alunos na escola " << GradeBook::numAlunosEscola << '\n';
    cout << "Inscricao de novos alunos " << numAlunos << '\n';
    if ( numAlunos > 0 )
        if ( ( numAlunos + GradeBook::numAlunosEscola ) <= MAXNUMALUNOSESCOLA )
        {
            this->numAlunos = numAlunos;
            GradeBook::numAlunosEscola += this->numAlunos;            
        }
        else
            if( ( MAXNUMALUNOSESCOLA - GradeBook::numAlunosEscola ) > 0 )
            {
              this->numAlunos =  MAXNUMALUNOSESCOLA - GradeBook::numAlunosEscola;
              GradeBook::numAlunosEscola += this->numAlunos; 
            }
            else
              this->numAlunos = 0;
    else
        this->numAlunos = 0;


    cout << "Novos alunos que conseguiram a matricula " << this->numAlunos << "\n\n";
}

string GradeBook::getCourseName( )
{
    return courseName;
} 

void GradeBook::displayMessage( bool check ) const
{
    if( check )
    {
        if( courseName.size( ) > 0 )
            cout << "Welcome to the Grade Book for course " << courseName << '.';          
        else
            cout << "Welcome to the Grade Book. Curso sem nome.";

        cout << " A Turma tem " << numAlunos << " aluno.\n";  
    }

}

void GradeBook::displayMessage( bool check )
{
    //Atribuição dentro da classe
    this->check = check;

    if( this-check )
    {
        if( courseName.size( ) > 0 )
            cout << "Welcome to the Grade Book for course " << courseName << '.';          
        else
            cout << "Welcome to the Grade Book. Curso sem nome.";

        cout << " A Turma tem " << numAlunos << " aluno.\n";  
    }

}

void GradeBook::printListaAlunos( ) const
{
    for( int i = 0; i < NUMALUNOSMIN; i++ )
        cout << alunos[ i ] << '\n';
}

void GradeBook::fornecerNotas( double grades[ ], int ngrades )
{
    if( NGRADES <= ngrades )
        for( int i = 0; i < NGRADES; i++ )
            this->grades[ i ] = grades[ i ]; 
}

void GradeBook::printGrades( ) const
{
    for( int i = 0; i < NGRADES; i++ )
        cout << this->grades[ i ] << '\n';
}