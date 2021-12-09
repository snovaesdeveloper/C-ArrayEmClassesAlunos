#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using std::string;

class GradeBook
{
public:

    GradeBook ( );    
    GradeBook( string , int = 0 );
    GradeBook( int );
    GradeBook( const GradeBook & );
    
    void setCourseName( string );
    
    void setNumAlunos( int );

    string getCourseName( );

    void displayMessage( bool = true ) const;
    void displayMessage( bool = true );

    //Métodos const não podem ser statics
    void printListaAlunos(  ) const;

    inline static int getnumGradeBooks( )   { return numGradeBooks; }
    inline static int getnumAlunosEscola( ) { return numAlunosEscola; }

    void fornecerNotas( double [ ], int );

    void printGrades( ) const;

private:

    string courseName;
    int numAlunos;
    const int MAXSIZENAME;
    bool check;
    static int numGradeBooks;
    //Error check. Static não pode instanciar no .h
    //static int numGradeBooks = 0;

    static int numAlunosEscola;

    //Error check: uma referência a um membro não estático deve ser relativa ao objeto específico C/C++(245)
    //const int NUMALUNOSMIN = 2;
    //static string alunos[ NUMALUNOSMIN ];

    //Sem erro
    static const int NUMALUNOSMIN = 2;
    static string alunos[ NUMALUNOSMIN ];

    static const int NGRADES = 5;
    double grades[ NGRADES ];

    //Pode inicializar aqui ou no cpp
    //const static int MAXNUMALUNOSESCOLA = 100;
    const static int MAXNUMALUNOSESCOLA;

};

#endif // GRADEBOOK_H