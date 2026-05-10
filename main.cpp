#include<iostream>
#include<string>
#include<windows.h>
#include<cctype> // biblioteca com funções úteis para tratar caracteres individuais
#include<ctime> // lib para pegar o tempo do computador
#include<vector> // bora guardar esses cadastros

struct Pessoa;
struct Endereco;
struct Cadastro;
int main();
int menuSelecaoCurso(int cursoSelecionado);
int cursosDisponiveis();
int realizarLogin(std::vector<Cadastro>& listaAlunos);
std::string limparString(std::string cpf);
bool validadorCPF(std::string cpfLimpo);
bool validadorEmail(std::string email);
bool validadorDataNascimento(std::string dataNascimento);
bool anoEhBissexto(int ano);
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

struct Pessoa cadastrarPessoa(std::string tipoPessoa){
    Pessoa p;

    std::string cpfDigitado; // vamos usar esse carinha aqui para verificar se o CPF digitado é valido antes de levar pro cadastro
    bool valido = false; // esse vai ser o nosso validador final, esperamos que ele retorne com um true para continuar o restante do código

    // CADASTRO NOME
    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Olá! Vamos seguir com o cadastro do "<<tipoPessoa<<"!"<<std::endl;
        std::cout<<"Por favor, informe o seu nome completo:"<<std::endl;
        std::getline(std::cin>>std::ws, p.nomeCompleto);

        if(p.nomeCompleto.empty()){
            std::cout<<"Seu nome não pode ficar vazio!"<<std::endl;
        }else{
            std::cout<<"Nome registrado com sucesso!"<<std::endl;
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
            valido = true;
        }
    }while(!valido);
    std::string nomeCompleto = p.nomeCompleto;
    size_t posEspaco = nomeCompleto.find(' '); // descobre o primeiro espaço
    std::string primeiroNome = nomeCompleto.substr(0, posEspaco); // recorta o resto da string, ficando somente antes da posição do espaço

    
    // CADASTRO CPF
    valido = false;
    do{ 

        std::cout<<primeiroNome<<", para continuar, vou precisar do seu CPF! Por favor, informe o seu CPF (apenas números ou com ponto/traço): "<<std::endl;
        std::getline(std::cin>>std::ws, cpfDigitado); // usando getline para caso de digitar 000 000 000 00

        std::string cpfLimpo = limparString(cpfDigitado); // beleza, criamos uma variavel chamada de cpfLimpo, que vai receber o cpf tratado na função limparString

        if(validadorCPF(cpfLimpo) == true){
            p.cpf = cpfLimpo;
            valido = true;
            std::cout<<"CPF Validado e cadastrado com sucesso!"<<std::endl;            
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        }else{
            std::cout<<"CPF Inválido, tente novamente."<<std::endl;
        }
    }while(!valido);

    // CADASTRAR RG
    valido = false;
    do{
        
        std::cout<<"Vou precisar do seu RG agora: "<<std::endl;
        std::getline(std::cin>>std::ws, p.rg);

        if(p.rg.empty()){
            std::cout<<"Seu RG não pode ficar vazio!"<<std::endl;
        }else if(p.rg.length() < 7 || p.rg.length() > 9){
            std::cout<<"RG inválido! Tente novamente."<<std::endl;
        }else{
            std::cout<<"RG Cadastrado com sucesso!"<<std::endl;
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
            valido = true;
        }
    }while(!valido);

    // CADASTRAR EMAIL

    valido = false;
    do{

        std::cout<<"Insira seu e-mail para o cadastro: "<<std::endl;
        std::getline(std::cin>>std::ws, p.email);

        if(p.email.empty()){
            std::cout<<"Seu e-mail não poode ficar vazio!"<<std::endl;
        }else if(validadorEmail(p.email)){
            std::cout<<"E-mail registrado com sucesso!"<<std::endl;
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
            valido = true;
        }else{
            std::cout<<"E-mail invalido! (Ex: usuario@gmail.com)"<<std::endl;
        }
    }while(!valido);
    
    // CADASTRAR DATA DE NASCIMENTO

    do{

        std::cout<<"Informe sua data de nascimento para continuar: (dd/mm/aaaa)"<<std::endl;
        std::getline(std::cin>>std::ws, p.dataNascimento);
        std::string dataNascimentoLimpa = limparString(p.dataNascimento);

        if(p.dataNascimento.empty()){
            std::cout<<"Sua data de nascimento não pode ficar vazia!"<<std::endl;
        }else if(dataNascimentoLimpa.length() != 8){
            std::cout<<"Data de Nascimento não pode ser menor/maior que 8 digitos (00/00/0000)"<<std::endl;
        }else if(validadorDataNascimento(dataNascimentoLimpa)){
            p.dataNascimento = dataNascimentoLimpa;
            std::cout<<"Sua data de nascimento foi cadastrada com sucesso!"<<std::endl;
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
            valido = true;
        }else{
            std::cout<<"Data de Nascimento inválida (dd/mm/aaa)"<<std::endl;
        }
    }while(!valido);

    return p;
};

struct Endereco cadastrarEndereco(std::string tipoPessoa){
    Endereco e;
    bool valido = false;

    std::cout<<"Finalizamos o seu cadastro pessoal, agora vamos precisa cadastrar o endereço do "<<tipoPessoa<<std::endl;

    // RUA
    std::cout<<"Digite o nome da sua rua: "<<std::endl;
    std::getline(std::cin>>std::ws, e.rua);
    std::cout<<"RUA cadastrada com sucesso!"<<std::endl;
    std::cout<<"------------------------------------------------------------------------------"<<std::endl;

    // NUMERO
    std::cout<<"Qual o número de sua residência?"<<std::endl;
    std::getline(std::cin>>std::ws, e.numero);
    std::cout<<"Número cadastrado com sucesso!"<<std::endl;
    std::cout<<"------------------------------------------------------------------------------"<<std::endl;

    // CEP
    do{
        std::cout<<"Qual o CEP da residência?"<<std::endl;
        std::getline(std::cin>>std::ws, e.cep);
        std::string cepLimpo = limparString(e.cep);

        if(cepLimpo.empty()){
            std::cout<<"CEP não pode ficar vazio!"<<std::endl;
        }else if(cepLimpo.length() != 8){
            std::cout<<"CEP inválido! tente novamente!"<<std::endl;
        }else{
            std::cout<<"CEP cadastrado com sucesso!"<<std::endl;
            std::cout<<"------------------------------------------------------------------------------"<<std::endl;
            valido = true;
            }
    }while(!valido);

    // Complemento
    std::cout<<"Algum complemento? Ex. apto, bloco, ponto de interesse"<<std::endl;
    std::getline(std::cin>>std::ws, e.complemento);
    std::cout<<"Complemento cadastrado com sucesso!"<<std::endl;
    std::cout<<"------------------------------------------------------------------------------"<<std::endl;

    return e;
}

Cadastro cadastroPessoaEndereco(){

    Cadastro novoCadastro;
    char resposta;

    novoCadastro.dadosAluno = cadastrarPessoa("Aluno");
    novoCadastro.enderecoAluno = cadastrarEndereco("Aluno");

    // Verificar se o responsável financeiro é o mesmo do aluno

    std::cout<<"O responsável financeiro é o próprio Aluno? Responda S/N:"<<std::endl;
    std::cin>>resposta;
    std::cin.ignore(1000, '\n'); // para limpar o buffer de qualquer "enter" que ainda tiver aqui para o próximo getline

    if(toupper(resposta) == 'S'){
        novoCadastro.dadosResponsavel = novoCadastro.dadosAluno;
        novoCadastro.enderecoResponsavel = novoCadastro.enderecoAluno;
        novoCadastro.responsavelFinanAluno = 'S';
        std::cout<<"Dados copiados do cadastro do aluno com sucesso!"<<std::endl;
    }else{
        novoCadastro.responsavelFinanAluno = 'N';
        novoCadastro.dadosResponsavel = cadastrarPessoa("Responsável");
        
        std::cout<<"O responsável mora junto com o aluno? Responsa S/N:"<<std::endl;

        char moraJunto;
        std::cin>>moraJunto;
        std::cin.ignore(1000, '\n');

        if(toupper(moraJunto) == 'S'){
            novoCadastro.enderecoResponsavel = novoCadastro.enderecoAluno;
            std::cout<<"Dados de endereço copiados do Aluno com sucesso!"<<std::endl;
        }else{
            novoCadastro.enderecoResponsavel = cadastrarEndereco("Responsável");
        };
    }

    novoCadastro.usuario = novoCadastro.dadosAluno.cpf;
    novoCadastro.senha = novoCadastro.dadosAluno.dataNascimento;


    std::cout<<"------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Cadastro concluído com sucesso!"<<std::endl;
    std::cout<<"Seu usuário para logar é: "<<novoCadastro.usuario<<std::endl;
    std::cout<<"Sua senha para logar é: "<<novoCadastro.senha<<std::endl;

    return novoCadastro;
};

std::string limparString(std::string stringSuja){ // o tal do limpas, vamos usar isso aqui com a biblioteca cctype para limpar os espaços, pontos, vírgulas ou qualquer caracter que não for um numeral
    
    std::string stringLimpa = ""; // variavel vazia para armazenar os números limpos

    for (char c : stringSuja){ // para cada caracter na stringSuja, verificar se é um digito númerico, se for, guardar esse dígito dentro da var apenasNumeros, no final, retornar esses números
        if (isdigit(c)){
            stringLimpa += c;
        }
    }
    return stringLimpa;
}

bool validadorCPF(std::string cpfLimpo){ // VALIDADOR DE CPF (NUMEROS IGUAS) (DIGITO IDENTIFICADOR)

    if(cpfLimpo.length() != 11) return false;

    bool repetido = true;
    for(int i = 1; i < 11; i++){ // verificar se todos os digitos de são iguais (se o i é diferente do primeiro numero, retorna falso, quer dizer que pode ser um cpf valido)
        if(cpfLimpo[i] != cpfLimpo[0]){
            repetido = false;
            break;
        }
    }
    
    if(repetido == true) return false;

    int somaD10 = 0; // se não colocar o 0, por algum motivo, não da certo, parece que o proprio codigo vem com um numero aleatorio
    int somaD11 = 0;
    int multiplicadorD10 = 10;
    int multiplicadord11 = 11;
    bool d10Valido = false;
    bool d11Valido = false;

    for(int i = 0; i < 9; i++){
        somaD10 += (cpfLimpo[i] - '0') * multiplicadorD10;
        multiplicadorD10--;
    }

    int calculoD10 = somaD10%11;
    int d10 = 11 - calculoD10;
    if(d10 == 10 || d10 == 11){
        d10 = 0;
    }

    if(d10 == (cpfLimpo[9] - '0')){
        d10Valido = true;
    }

    for(int i = 0; i < 10; i++){
        somaD11 += (cpfLimpo[i] - '0') * multiplicadord11;
        multiplicadord11--;
    }

    int calculoD11 = somaD11%11;
    int d11 = 11 - calculoD11;
    if(d11 == 10 || d11 == 11){
        d11 = 0;
    }

    if(d11 == (cpfLimpo[10] - '0')){
        d11Valido = true;
    }

    if(d10Valido && d11Valido) return true;

    return false;

}

bool validadorEmail(std::string email){ // VALIDADOR DE EMAIL (SE CONTEM @ E .) (SE NÃO ESTÃO NOS LUGARES ERRADOS)
    
    size_t posicaoArroba = email.find('@'); // size_t pois não sabemos o tamanho do e_mail, dependendo da situação, o int não vai guardar a posição, então, encontramos o @ e a pos dele
    size_t posicaoPonto = email.find('.', posicaoArroba); // aqui pedimos para ele encontrar um "ponto", mas que procure após a posição do arroba

    if(posicaoArroba != std::string::npos &&    // Verifica se posição do arroba existe na string (npos diz que não existe, mas aqui to pedindo !=)
        posicaoArroba > 0 &&                    // Verficia se o "@" não é o primeiro caracter
        posicaoPonto != std::string::npos &&    // mesma coisa, verifica se o ponto existe
        posicaoPonto < (email.length() - 1)){   // Verifica se o "."" não é o ultimo caracter
            return true;                        // Se tudo der certo, retorna que esta validado
        }

    return false;
}

bool validadorDataNascimento(std::string dataNascimento){ // VERIFICAR SE A DATA É VALIDA (TEM ESSE DIA NO MES)

    time_t t = time(0); // time_t tipo de variavel para guardar tempo, time(0) vai pegar o tempooperacional unix(total de segundos desde 01/01/1970)
    tm* dataAtual = localtime(&t); //tm é uma struct da lib ctime, *dataAtual é um ponteiro para onde estão os dados na memoria, localtime() é uma função para transofrmar em algo legivel o time(0)

    int anoAtual = dataAtual->tm_year + 1900; // -> pois como é um ponteiro, não é usado "." para pegar algo de dentro, que seria tm_year = 126 (ele conta quantos anos se passaram desde 1900)

    int dia = std::stoi(dataNascimento.substr(0,2)); // stoi = string to integer, vai transformar a string num int, substring vai criar uma string começando indice 0, e pegando 2 valores
    int mes = std::stoi(dataNascimento.substr(2,2));
    int ano = std::stoi(dataNascimento.substr(4,4)); 

    if(ano < 1900 || ano > anoAtual) return false; // se for antes de 1900 ou depois do ano atual, ta errado

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(anoEhBissexto(ano)) diasNoMes[2] = 29; // verifica se o ano é bissexto, se for, o mes 2 vira 29;

    if(dia < 1 || dia > diasNoMes[mes]) return false;

    if(ano == anoAtual){
        int mesAtual = dataAtual->tm_mon + 1; // pega o month(mes) atual e adiciona 1 (o mes dele vai de 0 a 11)
        if(mes > mesAtual) return false;
        if(mes == mesAtual && dia > dataAtual->tm_mday) return false; // se for o mesmo mes atual, não pode ser um dia mais avançado que hoje, embora aqui tu ta cadastrando um recem-nascido
    }

    return true;
};

bool anoEhBissexto(int ano){
    return (ano % 4 == 0 && (ano % 100) != 0 || (ano % 400) == 0);
}

int main(){ // MENU PRINCIPAL - INICIAL
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::vector<Cadastro> listaAlunos; // bem seguro, eu sei
    int escolhaMenu;
    int indiceLogado = -1; // usar para verificar qual usuario está logado, por padrão "-1", ninguem logado

    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Bem-vindo! Quem bom que escolheu o SENAC! Selecione uma opção para começar."<<std::endl;
        std::cout<<"1 - Conhecer Cursos"<<std::endl<<"2 - Cadastrar Aluno"<<std::endl<<"3 - Logar"<<std::endl<<"0 - Sair"<<std::endl;
        std::cin>>escolhaMenu;

        switch(escolhaMenu){
            case 1:
                cursosDisponiveis();
                break;
            case 2: 
                listaAlunos.push_back(cadastroPessoaEndereco()); // aqui já faz o cadastro e já coloca dentro do vector
                std::cout<<"Total de Alunos no sistema: "<<listaAlunos.size()<<std::endl; // só pra ver se deu tudo certo mesmo
                break;
            case 3:
                indiceLogado = realizarLogin(listaAlunos); // bora tentar logar
                if(indiceLogado != -1){ // se for != -1 quer dizer que alguem ta logado
                    std::cout<<"Sessão ativa para: "<<listaAlunos[indiceLogado].dadosAluno.nomeCompleto<<std::endl;
                }
                break;
            case 0:
                std::cout<<"Obrigado pela sua atenção! Até mais."<<std::endl;
                return 0;
            default:
                std::cout<<"Número Inválido!"<<std::endl;
                break;
        }
    }while(escolhaMenu != 0);

    return 0;
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
                menuSelecaoCurso(1);
                return 1;
            case 2:
                std::cout<<"Curso Técnico em Enfermagem!"<<std::endl;
                std::cout<<"Um curso contendo 1.600 horas totais, com turmas disponíveis de SEG a SEX, das 19h às 22h ou das 09h às 12h"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso são: a Carol e a Thamise!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 15.278,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(2);
                return 2;
            case 3:
                std::cout<<"Curso Técnico em Modelagem do Vestuário!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com turmas disponíveis em 2 escalas, escala 1: SEG, QUA e SEX, das 19h às 22h. Escala 2: TER e SEX das 19h às 22h"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso são: a Natália e o Ramon!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 14.844,79, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(3);
                return 3;
            case 4:
                std::cout<<"Curso EAD de Recursos Humanos!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.355,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(4);
                return 4;
            case 5:
                std::cout<<"Curso EAD de Logística!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.751,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(5);
                return 5;
            case 6:
                std::cout<<"Curso EAD de Contabilidade!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.355,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(6);
                return 6;
            case 7:
                std::cout<<"Curso EAD de Transações Mobiliares!"<<std::endl;
                std::cout<<"Um curso contendo 800 horas totais, com um tempo de formação de 12 meses, você faz o seu próprio horário!"<<std::endl;
                std::cout<<"Docentes responsáveis pelo curso sendo um grupo de especialistas selecionados a dedo!"<<std::endl;
                std::cout<<"O custo do curso hoje está saindo por R$ 3.157,00, tendo opções de desconto conforme forma de pagamento."<<std::endl;
                menuSelecaoCurso(7);
                return 7;
            case 9:
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

int realizarLogin(std::vector<Cadastro>& listaAlunos){
    std::string userDigitado, senhaDigitada;
    bool logou = false;

    do{
        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Area de Login"<<std::endl;
        std::cout<<"Usuário (CPF): "<<std::endl;
        std::cin>>userDigitado;
        std::cout<<"Senha (Data): "<<std::endl;
        std::cin>>senhaDigitada;

        for(int i = 0; i < listaAlunos.size(); i++){
            if (listaAlunos[i].usuario == userDigitado && listaAlunos[i].senha == senhaDigitada){
                
                std::string nomeCompleto = listaAlunos[i].dadosAluno.nomeCompleto;
                size_t posEspaco = nomeCompleto.find(' '); // descobre o primeiro espaço
                std::string primeiroNome = nomeCompleto.substr(0, posEspaco); // recorta o resto da string, ficando somente antes da posição do espaço
                std::cout<<"------------------------------------------------------------------------------"<<std::endl;
                std::cout<<"Usuário logado com sucesso! Seja bem vindo, "<<primeiroNome<<"!"<<std::endl;
                logou = true;
                return i;
            }
        }

        std::cout<<"------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Usuário ou senha incorretos!"<<std::endl;
        std::cout<<"1 - Tentar novamente"<<std::endl;
        std::cout<<"2 - Voltar ao Menu Inicial"<<std::endl;
        std::cout<<"Selecione uma opção para continuar"<<std::endl;
        int op;
        std::cin>>op;
        if(op == 2) return -1;
    }while(!logou);

    return -1;
};