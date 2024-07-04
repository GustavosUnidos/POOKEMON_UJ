# POOKEMON_UJ
Repositório destinado a versionar os códigos relacionados a matéria de Programação a Objetos

--- 
## Batalha Pokémon em C++

Este projeto simula uma batalha entre Pokémon usando C++ e orientação a objetos. Abaixo está uma explicação detalhada sobre a estrutura do código, seus componentes principais e como executá-lo.

### Estrutura do Projeto

O projeto consiste em várias classes que representam diferentes tipos de Pokémon e uma classe principal que gerencia a batalha entre eles.

- **Classes Principais**:
  - **Pokemon**: Classe base abstrata que define os atributos e métodos básicos de um Pokémon.
  - **PokemonFogo, PokemonAgua, PokemonPlanta**: Classes derivadas de Pokémon que representam tipos específicos de Pokémon com ataques característicos.
  - **Pikachu, Chimchar, Piplup**: Novos Pokémon adicionados ao sistema, cada um com seus próprios ataques exclusivos.
  
- **Métodos e Atributos**:
  - Cada Pokémon tem atributos como nome, ataque, defesa e pontos de vida (HP).
  - Métodos para atacar outros Pokémon (`atacar` e ataques específicos como `atacarBrasas`, `atacarHidroBomba`, etc.).
  - Métodos para defender de ataques (`defender`) e verificar se o Pokémon está vivo (`estaVivo`).

- **Funções Auxiliares**:
  - **batalha**: Função principal que simula a batalha entre dois Pokémon escolhidos pelo jogador e dois Pokémon controlados pelo computador.
  - **menu**: Função que permite ao jogador escolher seus Pokémon antes de iniciar a batalha.

- **Lógica de Batalha**:
  - A lógica da batalha é implementada no loop principal da função `batalha`, onde os jogadores e os Pokémon controlados pelo computador se alternam em ataques até que todos os Pokémon de um lado sejam derrotados.
