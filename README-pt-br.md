## Projeto Agree

## Sobre

Agree  é um projeto, feito com C++, similar a um programa chamado Discord. Ele possui servidores, usuários, canais e interações entre todos eles. Cada interação é possível usando um comando por linha, com cada linha válida sendo executada pelo projeto. Para aprender como usá-lo, veja os tópicos <a href="#compilando">Compilando</a> e <a href="#exemplos-de-comandos-de-entrada-e-saída">Exemplos de comandos de Entrada e Saída</a>.

Este projeto usa um template de código feito pelo professor Isaac Franco Fernandes (https://github.com/isaacfranco). Você pode ver seu código em https://github.com/isaacfranco/lp1-concordo-base.

O Projeto Agree é uma tarefa apresentada em uma aula chamada 'Linguagem de Programação I', lecionada pelo professor Renan Moioli, no curso de TI na Universidade Federal do Rio Grande do Norte. Este projeto possui três partes, para mais detalhes veja o tópico <a href="#explicação-sobre-cada-parte-deste-projeto">Explicação sobre cada parte deste projeto</a>.


## Compilando

Um arquivo Makefile é usado para compilar este projeto. Dentro da pasta raiz do projeto, assumindo que `$` é o prompt do terminal, siga os seguintes passos:

    ```
    # Clone o projeto
    $ git clone https://github.com/breudes/agree.git   
    # Compile o projeto
    $ make     
    # Execute 
    $ ./main < ./src/txt/script.txt
    ```

Neste projeto, você possui duas opções:
    
1. Você pode usar o arquivo 'script.txt' para definir todos os comandos de uma vez, fazendo com que o projeto os execute de um vez também. Para testar comandos diferentes, você pode alterar o aquivo .txt e digitar './main < ./src/txt/script.txt' novamente; e para saber de exemplos de comando, veja o tópico <a href="#exemplos-de-comandos-de-entrada-e-saída">Exemplos de comandos de Entrada e Saída</a>;
    
2. Você pode usar apenas o comando ./main e ir adicionando os outros comandos, um por linha. Neste caso, uma saída irá ser mostrada considerando cada comando.
    
Ps: este arquivo 'script.txt' contém todos os comandos por padrão para facilitar o teste de execução do projeto. Mas sinta-se livre para mudar esse arquivo da maneira que quiser.

## Explicação sobre cada parte deste projeto

1. Parte Um

Primeira parte é onde alguns métodos foram implementados para interagir com usuários e servidores. Métodos como criar usuário e servidor, atualizar informação do servidor, remover ou entrar no servidor. Cada comando e exemplo de entrada está no próximo tópico <a href="#exemplos-de-comandos-de-entrada-e-saída">Exemplos de comandos de Entrada e Saída</a>, sinta-se livre para usar este tópico como um guia para lhe guiar no sistema.

2. Parte Dois 

Segunda parte é onde alguns métodos foram implementados para interagir com os canais (de texto ou voz, claro). O que significa que alguns métodos foram implementados para criar, entrar ou deixar um servidor; da mesma maneira alguns métodos foram implementados para enviar uma mensagem em algum canal, para listar todas mensagens de um certo canal, listar todos canais de um servidor ativo, etc. Todos canais e mensagens são parte de algum servidor, então todos serão salvados ou carregados em servidores.

3. Parte Três

Nesta terceira e última parte, foram implementados dois métodos principais: salvar e carregar, que acabam atingindo 4 outros métodos, sendo eles: salvar usuários, salvar servidores, carregar usuários e carregar servidores. Os primeiros dois vem do método 'salvar', onde o Sistema Agree salva todos os dados de usuários ativos e servidores. O mesmo acontece com os últimos dois métodos, originários do método 'carregar', onde o Sistema Agree carrega todos os dados de usuários e servidores anteriores. Isso só é possível criando-se dois arquivos .txt: usuários e servidores, com esses dois arquivos o usuário pode salvar e carregar qualquer dado dessas classes no Sistema Agree.

Ps: os aquivos .txt estão no caminho: ./src/txt/data, caso você queira limpá-los os escrever neles.

## Exemplos de comandos de Entrada e Saída

Como foi dito, este projeto possui três parte, a primeira parte inclui os exemplos 1-12 e a segunda parte, exemplos 13-16. Veja todos os exemplos de entradas e saídas, intitulados por comando:

1. quit
    Este comando pode ser digitado qualquer hora enquanto Agree está executando, não importando se um usuário está logado ou não.

    > quit 
    > You're logging off from Agree System. Goodbye!

2. create-user
    - estrutura: create-user <user's email> <user's password> <user's name>
    - exemplo 01: 
        > create-user mareep@gmail.com 12345 mareep
        > Created user!
    - exemplo 02: 
        > create-user mareep@gmail.com 12345 mareep de souza batista
        > Created user!
    - mas se o usuário já existir, aqui está a saída:
        > User already exists!
    
3. login 
    - estrutura: login <user's email> <user's password>
    - exemplo: 
        > login bulbasaur@outlook.com flower
        > You're now logged as 'bulbasaur@outlook.com' on Agree System!
    - mas se o email ou senha estiverem inválidos, aqui está a saída:
        > User not found. You can try again!
    ou 
        > Invalid user's password!

4. disconnect
    Este comando desconecta o usuário logado no momento, mas Agree continuará executando. Ele só iria parar se o comando fosse 'quit'.
        > disconnect
        > Disconnecting user "bulbasaur@outlook.com"
        > Note that Agree System is still on!
    - mas se não há um usuário logado, a saída seria a seguinte:
        > Not connected!
        > Note that Agree System is still on!

5. create-server
    Antes de tudo, um servidor possui um nome e um código de convite opcional, para que futuros membros possam entrar; mas, quando você cria um servidor, o código de convite ainda não está configurado, podendo ser definido com outro comando, se você quiser.
        
    Este comando só fica disponível se o Sistema Agree tem pelo menos um usuário logado para criar o servidor. Caso contrário, a saída será "Enter with an user before create a server!". Depois de criado, você será o único dono do servidor.

    - estrutura: create-server <server's name>
    - exemplo:
        > create-server pokemons
        > Created server!
    - mas se já existe um servidor com esse nome, aqui seria a saída:
        > Server already exists with this name!

    Os próximos comandos requerem que pelo menos um usuário esteja logado no Agree, e que ele seja o dono de um certo servidor. Esta regra não se aplica ao comando 'list-servers'.

6. set-server-desc
    - estrutura: set-server-desc <server's name> <server's new description>
    - exemplo 01 (você é o dono do servidor): 
        > set-server-desc pokemons all pokemons that I really like
        > Modified 'pokemons' server description!
    - exemplo 02 (você não é o dono):
        > set-server-desc pokemons all pokemons that I really like
        > You cannot change another user's server description!

    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".

7. set-server-invite-code
    - estrutura: set-server-invite-code <server's name> <server's new invite code>
    - exemplo 01 (configurar um servidor como servidor privado): 
        > set-server-invite-code pokemons 123456
        > Set 'pokemons' server invite code!
    - exemplo 02 (configurar um servidor como servidor aberto):
        > set-server-invite-code pokemons 
        > Set 'pokemons' server invite code!

    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".
        
8. list-servers
        > list-servers
        > List of all servers on Agree System: 
        > pokemons
        > earth
        > avatar
        > korra

9. remove-server
    - estrutura: remove-server <server's name>
    - exemplo 01 (você é o dono do servidor):
        > remove-server pokemons
        > Removed 'pokemons' server!
    - exemplo 02 (você não é o dono):
        > remove-server pokemons
        > You are not the owner of the 'pokemons' server
        
    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".

10. enter-server
    - estrutura: enter-server <server's name>
    - exemplo 01 (servidor sem código de convite): 
        > enter-server pokemons
        > This is an open server!
        > Entering 'pokemons' server!
    - exemplo 02 (servidor com código de convite):
        > enter-server earth 123
        > This is a closed server. You need an invite code to enter!
        > Entering 'earth' server!
    - mas se o código de convite for inválido, aqui seria a saída: 
        > This is a closed server. You need an invite code to enter!
        > Invalid invite code for this server. You can try again!

    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".

11. leave-server
        > leave-server
        > Leaving 'pokemons' server!
    - mas se não há servidor ligado ao usuário atual, aqui seria a saída:
        > You are not viewing any servers

    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".

12. list-participants

    Este comando irá somente mostrar os nomes dos membros do servidor ativo atual, se o usuário logado atualmente no Agree estiver em um certo servidor. Todos nomes foram recuperados pelo id do usuário.

        > list-participants
        > List of all members on server 'pokemons'
        > mareep
        > bulbasaur
        > cyndaquil

    E se o nome do servidor fosse inválido, a saída seria apenas "Server not found! You can try again!".

Ps: For this commands, you'll have to be logged on some server on Agree System, otherwise, it won't let you execute these commands. 

13. list-channels
    > list-channels
    > List of channels on the current server 'pokemons'
    > earth
    > water
14. create-channel
    - estrutura: create-channel <'channel's name'> <'channel's type'>
    - exemplo 01:
        > create-channel earth text 
        > A text channel 'earth' created on this server!
    - exemplo 02:
        > create-channel water voice
        > A voice channel 'water' created on this server!
15. enter-channel
    - estrutura: enter-channel <'channel's name'>
        > enter-channel earth
        > Entered the channel 'earth' !
16. leave-channel
    > leave-channel
    > Leaving channel 'earth' of server 'pokemons'
17. send-message
    Nota: este comando está disponível somente se você estiver logado em um servidor e canal, senão ele não executará.
    - estrutura: send-message <'message's content'>
    - exemplo: 
        > send-message hi how are u?
18. list-messages
    Nota: este comando está disponível somente se você estiver logado em um servidor e canal, senão ele não executará.
    > list-messages
    > mareep
    > <04/21/2021 - 14:40>:hi how are u?

    Se não existir mensagens disponíveis, então a saída será "There is no messages to display."
    
## Feedback (Limitações e Dificuldades)

Este projeto foi mais fácil que projetos anteriores pois no Agree nós usamos o vetor como estrutura de dados, tanto nas classes Server e System. A limitação foi o conteúdo de herança pois eu estudei isso há muito tempo, então foi um pouco complicado implementá-lo.

## Autora e Colaboradores

Este projeto foi feito por breudes (https://github.com/breudes). Nome completo da autora: Brenda Alexandra de Souza Silva. Mas, novamente, foi usado um código base do professor Isaac Franco Fernandes (https://github.com/isaacfranco), então Isaac também é um co-autor ou colaborador deste projeto.

Você pode ver seu código base em https://github.com/isaacfranco/lp1-concordo-base.
    
## Licença

Este projeto está sob licença do MIT. Veja LICENSE para mais detalhes.
