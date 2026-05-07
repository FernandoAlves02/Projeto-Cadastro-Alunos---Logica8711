#include<iostream>
#include<string>
#include<windows.h>

int main();
int menuSelecaoCurso(int cursoSelecionado);
int cursosDisponiveis();
int cadastroAluno();

int main(){ // MENU PRINCIPAL - INICIAL
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int escolhaMenu;

    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Bem-vindo! Quem bom que escolheu o SENAC! Selecione uma opção para começar."<<std::endl;
        std::cout<<"1 - Conhecer Cursos"<<std::endl<<"2 - Cadastrar Aluno"<<std::endl<<"0 - Sair"<<std::endl;
        std::cin>>escolhaMenu;

        switch(escolhaMenu){
            case 1:
                cursosDisponiveis();
                return 1;
            case 2:
                cadastroAluno();
                return 2;
            case 0:
                std::cout<<"Obrigado pela sua atenção! Até mais."<<std::endl;
                return 0;
            default:
                std::cout<<"Número Inválido!"<<std::endl;
                break;
        }
    }while(true);
}

int cursosDisponiveis(){ // MENU COM OS CURSOS
    int escolhaMenuCursos;

    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Claro! Vamos verificar os cursos disponíveis: "<<std::endl;
        std::cout<<"Presenciais: "<<std::endl;
        std::cout<<"1 - Técnico em Desenvolvimento de Sistemas"<<std::endl;
        std::cout<<"2 - Técnico em Enfermagem"<<std::endl;
        std::cout<<"3 - Técnico em Modelagem do Vestuário"<<std::endl;
        std::cout<<"Ensino a Distância: "<<std::endl;
        std::cout<<"4 - Recursos Humanos"<<std::endl;
        std::cout<<"5 - Logística"<<std::endl;
        std::cout<<"6 - Contabilidade"<<std::endl;
        std::cout<<"7 - Transações Mobiliares"<<std::endl<<std::endl;
        std::cout<<"Tem algum curso que te interessou? Escolha um número para verificar o curso ou escolha uma das opções abaixo:"<<std::endl;
        std::cout<<"9 - Menu Principal"<<std::endl;
        std::cout<<"0 - Sair"<<std::endl;
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cin>>escolhaMenuCursos;

        switch (escolhaMenuCursos){
            case 1:
                std::cout<<"Curso Técnico em Desenvolvimento de Sistemas!"<<std::endl;
                std::cout<<"Um curso contendo 1.216 horas totais, com turmas disponíveis de SEG a SEX, das 19h às 22h;"<<std::endl;
                std::cout<<"Docente responsável pelo curso é o Ilustre Mestre Eduardo, uma pessoa Jovial e de muito charme!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 14.405,49, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(1);
                return 1;
            case 2:
                std::cout<<"Curso Técnico em Enfermagem!"<<std::endl;
                std::cout<<"Um curso contendo 1.600 horas totais, com turmas disponíveis de SEG a SEX, das 19h às 22h ou das 09h às 12h"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso são: a Carol e a Thamise!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 15.278,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(2);
                return 2;
            case 3:
                std::cout<<"Curso Técnico em Modelagem do Vestuário!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com turmas disponíveis em 2 escalas, escala 1: SEG, QUA e SEX, das 19h às 22h. Escala 2: TER e SEX das 19h às 22h"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso são: a Natália e o Ramon!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 14.844,79, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(3);
                return 3;
            case 4:
                std::cout<<"Curso EAD de Recursos Humanos!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.355,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(4);
                return 4;
            case 5:
                std::cout<<"Curso EAD de Logística!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.751,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(5);
                return 5;
            case 6:
                std::cout<<"Curso EAD de Contabilidade!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.355,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(6);
                return 5;
            case 7:
                std::cout<<"Curso EAD de Transações Mobiliares!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.157,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                std::cout<<menuSelecaoCurso(7);
                return 7;
            case 9:
                main();
                return 9;
            case 0:
                std::cout<<"Obrigado pela sua atenção! Até mais."<<std::endl;
                return 0;
            default:
                std::cout<<"Número Inválido!"<<std::endl;
                break;
        }

    }while(true);
    
    return 0;
}

int menuSelecaoCurso(int cursoSelecionado){ // OPÇÕES DE MENU - MATRICULAR NO CURSO
    int escolhaMenuSelecao;

    int valoresCurso[7];
    valoresCurso[0] = 14405.49;
    valoresCurso[1] = 15278.00;
    valoresCurso[2] = 14844.79;
    valoresCurso[3] = 3355.00;
    valoresCurso[4] = 3751.00;
    valoresCurso[5] = 3355.00;
    valoresCurso[6] = 3157.00;

    valoresCurso[(cursoSelecionado - 1)]; // usar para puxar o valor, provavelmente levar esse dado para a matricula do curso

    do{
        std::cout<<"Escolha uma das opções abaixo para continuar"<<std::endl;
        std::cout<<"1 - Se matricular no curso"<<std::endl;
        std::cout<<"8 - Menu de Cursos"<<std::endl;
        std::cout<<"9 - Menu Principal"<<std::endl;
        std::cout<<"0 - Sair"<<std::endl;
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cin>>escolhaMenuSelecao;
                    
        switch (escolhaMenuSelecao){
            case 1:
                //matricularCurso();
                break;
            case 8:
                cursosDisponiveis();
                return 8;
            case 9:
                main();
                return 9;
            case 0:
                std::cout<<"Obrigado pela sua atenção! Até mais."<<std::endl;
                return 0;
            default:
                std::cout<<"Número Inválido!"<<std::endl;
                break;
        }
    }while(true);

    return 0;
}

int cadastroAluno(){ //CADASTRO DO ALUNO

    bool cadastroConcluido = false; // Verificador se usuario já cadastrado

    std::string nomeCompletoAluno;
    std::string enderecoAluno[4]; // Juntar todos os pedaços do endereço
    std::string ruaEnderecoAluno;
    std::string numeroEnderecoAluno;
    std::string cepEnderecoAluno;
    std::string complementoEnderecoAluno;
    std::string alunoCPF;
    std::string alunoRG;
    std::string alunoEmail;
    std::string dataNascimentoAluno; // Lembrar de pegar os 4 ultimos digitos e forçar de que os 4 ultimos digitos devem ser um ano
    bool responsavelFinanAluno;

    std::string nomeCompletoResponsavel;
    std::string enderecoResponsavel[4];
    std::string ruaEnderecoResponsavel;
    std::string cepEnderecoResponsavel;
    std::string complementoEnderecoResponsavel;
    std::string responsavelCPF;
    std::string responsavelRG;
    std::string responsavelEmail;
    std::string dataNascimentoResponsavel;

    return 0;

}