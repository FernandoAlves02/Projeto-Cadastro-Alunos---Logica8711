#include<iostream>
#include<string>
#include<windows.h>
#include<cctype> // biblioteca com funções úteis para tratar caracteres individuais

int main();
int menuSelecaoCurso(int cursoSelecionado);
int cursosDisponiveis();
int menuCadastro();
int cadastrar();
std::string limparCPF(std::string cpf);
bool validadorCPF(std::string cpfLimpo);
// iniciando as funções aqui em cima para não dar erro de escopo depois

struct Pessoa {
    std::string nomeCompleto;
    std::string cpf;
    std::string rg;
    std::string email;
    std::string dataNascimento; // Lembrar de pegar os 4 ultimos digitos e forçar de que os 4 ultimos digitos devem ser um ano

};

struct Endereco {
    std::string rua;
    std::string numero;
    std::string cep;
    std::string complemento;
};

struct Cadastro {
    std::string usuario;
    std::string senha;

    Pessoa dadosAluno;
    Endereco enderecoAluno;

    char responsavelFinanAluno; // S/N

    Pessoa dadosResponsavel;
    Endereco enderecoResponsavel;
};

// por algum motivo, 1° structs, depois funções

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
                menuCadastro();
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

    float valoresCurso[7];
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

std::string limparCPF(std::string cpf){ // o tal do limpas, vamos usar isso aqui com a biblioteca cctype para limpar os espaços, pontos, vírgulas ou qualquer caracter que não for um numeral
    
    std::string apenasNumeros = ""; // variavel vazia para armazenar os números limpos

    for (char c : cpf){ // para cada caracter C em cpf, verificar se é um digito númerico, se for, guardar esse dígito dentro da var apenasNumeros, no final, retornar esses números
        if (isdigit(c)){
            apenasNumeros += c;
        }
    }
    return apenasNumeros;
}

bool validadorCPF(std::string cpfLimpo){

    if(cpfLimpo.length() != 11){ 
        return false;
    }

    bool repetido = true;
    for(int i = 1; i < 11; i++){ // verificar se todos os digitos de são iguais (se o i é diferente do primeiro numero, retorna falso, quer dizer que pode ser um cpf valido)
        if(cpfLimpo[i] != cpfLimpo[0]){
            repetido = false;
            break;
        }
    }
    
    if(repetido == true){
        return false;
    } 

    return true;

}

int menuCadastro(){ //CADASTRO DO ALUNO

    //bool cadastroConcluido = false; // Verificador se usuario já cadastrado

    int escolhaCadastro;

    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Selecione a opção desejada abaixo."<<std::endl;
        std::cout<<"1 - Cadastrar"<<std::endl;
        std::cout<<"2 - Logar"<<std::endl;
        std::cout<<"9 - Menu Principal"<<std::endl;
        std::cout<<"0 - Sair"<<std::endl;
        std::cin>>escolhaCadastro;

        switch (escolhaCadastro){
            case 1:
                cadastrar();
                return 1;
            case 2:
                //logar();
                return 2;
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

int cadastrar(){

    Cadastro novoCadastro;
    std::string cpfDigitado; // vamos usar esse carinha aqui para verificar se o CPF digitado é valido antes de levar pro cadastro
    bool cpfValido = false; // esse vai ser o nosso validador final, esperamos que ele retorne com um true para continuar o restante do código

    std::cout<<"------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Olá! Vamos seguir com o seu cadastro!"<<std::endl;
    std::cout<<"Por favor, informe o seu nome completo:"<<std::endl;
    std::getline(std::cin>>std::ws, novoCadastro.dadosAluno.nomeCompleto);

    std::string nomeCompleto = novoCadastro.dadosAluno.nomeCompleto;
    size_t posEspaco = nomeCompleto.find(' '); // descobre o primeiro espaço
    std::string primeiroNome = nomeCompleto.substr(0, posEspaco); // recorta o resto da string, ficando somente antes da posição do espaço

    // ACIMA, NOME, ABAIXO, CPF

    do{ // usar um loop do:while para manter o usuário no loop enquanto cpf não for valido

        std::cout<<primeiroNome<<", para continuar, vou precisar do seu CPF! Por favor, informe o seu CPF (apenas números ou com ponto/traço): "<<std::endl;
        std::getline(std::cin>>std::ws, cpfDigitado); // usando getline para caso de digitar 000 000 000 00

        std::string cpfLimpo = limparCPF(cpfDigitado); // beleza, criamos uma variavel chamada de cpfLimpo, que vai receber o cpf tratador na função limparCPF

        if(validadorCPF(cpfLimpo) == true){
            novoCadastro.dadosAluno.cpf = cpfLimpo;
            cpfValido = true;
            std::cout<<"CPF Validado com sucesso!"<<std::endl;
        }else{
            std::cout<<"CPF Inválido, tente novamente."<<std::endl;
        }
    }while(!cpfValido);


    return 0;
}