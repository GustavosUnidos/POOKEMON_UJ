#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

class Pokemon {
protected:
    string nome;
    int ataque;
    int defesa;
    int hp;

public:
    Pokemon(string nome, int ataque, int defesa, int hp)
        : nome(nome), ataque(ataque), defesa(defesa), hp(hp) {}

    virtual void atacar(Pokemon& outroPokemon) = 0;

    void defender(int dano) {
        int danoRecebido = max(0, dano - defesa);
        hp -= danoRecebido;
        hp = max(hp, 1); 
        cout << nome << " recebeu " << danoRecebido << " de dano! HP restante: " << hp << endl;
    }

    bool estaVivo() const {
        return hp > 0;
    }

    string getNome() const {
        return nome;
    }
};

class PokemonFogo : public Pokemon {
public:
    PokemonFogo(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque de Fogo!" << endl;
        int dano = ataque + (rand() % 11) + 5;
        outroPokemon.defender(dano);
    }

    void atacarBrasas(Pokemon& outroPokemon) {
        cout << nome << " usa Brasas!" << endl;
        int dano = ataque + (rand() % 8) + 3;
        outroPokemon.defender(dano);
    }
};

class PokemonAgua : public Pokemon {
public:
    PokemonAgua(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque de Água!" << endl;
        int dano = ataque + (rand() % 10) + 3;
        outroPokemon.defender(dano);
    }

    void atacarHidroBomba(Pokemon& outroPokemon) {
        cout << nome << " usa Hidro Bomba!" << endl;
        int dano = ataque + (rand() % 12) + 4;
        outroPokemon.defender(dano);
    }
};

class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque de Planta!" << endl;
        int dano = ataque + (rand() % 11) + 4;
        outroPokemon.defender(dano);
    }

    void atacarFolhaNavalha(Pokemon& outroPokemon) {
        cout << nome << " usa Folha Navalha!" << endl;
        int dano = ataque + (rand() % 10) + 3;
        outroPokemon.defender(dano);
    }
};


class Pikachu : public Pokemon {
public:
    Pikachu(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacarRaio(Pokemon& outroPokemon) {
        cout << nome << " usa Raio!" << endl;
        int dano = ataque + (rand() % 10) + 3;
        outroPokemon.defender(dano);
    }

    void atacarChoque(Pokemon& outroPokemon) {
        cout << nome << " usa Choque!" << endl;
        int dano = ataque + (rand() % 8) + 2;
        outroPokemon.defender(dano);
    }

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque Normal!" << endl;
        int dano = ataque + (rand() % 6) + 1;
        outroPokemon.defender(dano);
    }
};

class Chimchar : public Pokemon {
public:
    Chimchar(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacarChama(Pokemon& outroPokemon) {
        cout << nome << " usa Chama!" << endl;
        int dano = ataque + (rand() % 9) + 3;
        outroPokemon.defender(dano);
    }

    void atacarArranhao(Pokemon& outroPokemon) {
        cout << nome << " usa Arranhão!" << endl;
        int dano = ataque + (rand() % 7) + 2;
        outroPokemon.defender(dano);
    }

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque Normal!" << endl;
        int dano = ataque + (rand() % 6) + 1;
        outroPokemon.defender(dano);
    }
};

class Piplup : public Pokemon {
public:
    Piplup(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacarJato(Pokemon& outroPokemon) {
        cout << nome << " usa Jato!" << endl;
        int dano = ataque + (rand() % 8) + 3;
        outroPokemon.defender(dano);
    }

    void atacarGolpe(Pokemon& outroPokemon) {
        cout << nome << " usa Golpe!" << endl;
        int dano = ataque + (rand() % 6) + 2;
        outroPokemon.defender(dano);
    }

    void atacar(Pokemon& outroPokemon) override {
        cout << nome << " usa Ataque Normal!" << endl;
        int dano = ataque + (rand() % 6) + 1;
        outroPokemon.defender(dano);
    }
};

void batalha(Pokemon& jogador1, Pokemon& jogador2, vector<Pokemon*>& oponentes) {
    int turno = 1;
    while ((jogador1.estaVivo() || jogador2.estaVivo()) && (oponentes[0]->estaVivo() || oponentes[1]->estaVivo())) {
        cout << "\nTurno " << turno << endl;

        // Jogador escolhe qual Pokémon atacar
        int escolhaJogador;
        cout << "Escolha o Pokémon para atacar:" << endl;
        cout << "1. " << jogador1.getNome() << endl;
        cout << "2. " << jogador2.getNome() << endl;
        cout << "Escolha: ";
        cin >> escolhaJogador;

        Pokemon* pokemonDoJogador = (escolhaJogador == 1) ? &jogador1 : &jogador2;

        int escolhaOponente;
        cout << "Escolha o Pokémon do oponente para atacar:" << endl;
        cout << "1. " << oponentes[0]->getNome() << endl;
        cout << "2. " << oponentes[1]->getNome() << endl;
        cout << "Escolha: ";
        cin >> escolhaOponente;

        Pokemon* pokemonDoOponente = oponentes[escolhaOponente - 1];

        int escolhaAtaque;
        cout << "Escolha o ataque para " << pokemonDoJogador->getNome() << ":" << endl;
        
        if (dynamic_cast<PokemonFogo*>(pokemonDoJogador) != nullptr) {
            cout << "1. Ataque de Fogo" << endl;
            cout << "2. Brasas" << endl;
        } else if (dynamic_cast<PokemonAgua*>(pokemonDoJogador) != nullptr) {
            cout << "1. Ataque de Água" << endl;
            cout << "2. Hidro Bomba" << endl;
        } else if (dynamic_cast<PokemonPlanta*>(pokemonDoJogador) != nullptr) {
            cout << "1. Ataque de Planta" << endl;
            cout << "2. Folha Navalha" << endl;
        } else if (dynamic_cast<Pikachu*>(pokemonDoJogador) != nullptr) {
            cout << "1. Raio" << endl;
            cout << "2. Choque" << endl;
        } else if (dynamic_cast<Chimchar*>(pokemonDoJogador) != nullptr) {
            cout << "1. Chama" << endl;
            cout << "2. Arranhão" << endl;
        } else if (dynamic_cast<Piplup*>(pokemonDoJogador) != nullptr) {
            cout << "1. Jato" << endl;
            cout << "2. Golpe" << endl;
        }
        cout << "Escolha: ";
        cin >> escolhaAtaque;

        if (escolhaAtaque == 1) {
            pokemonDoJogador->atacar(*pokemonDoOponente);
        } else if (escolhaAtaque == 2) {
            if (dynamic_cast<PokemonFogo*>(pokemonDoJogador) != nullptr) {
                static_cast<PokemonFogo*>(pokemonDoJogador)->atacarBrasas(*pokemonDoOponente);
            } else if (dynamic_cast<PokemonAgua*>(pokemonDoJogador) != nullptr) {
                static_cast<PokemonAgua*>(pokemonDoJogador)->atacarHidroBomba(*pokemonDoOponente);
            } else if (dynamic_cast<PokemonPlanta*>(pokemonDoJogador) != nullptr) {
                static_cast<PokemonPlanta*>(pokemonDoJogador)->atacarFolhaNavalha(*pokemonDoOponente);
            } else if (dynamic_cast<Pikachu*>(pokemonDoJogador) != nullptr) {
                static_cast<Pikachu*>(pokemonDoJogador)->atacarChoque(*pokemonDoOponente);
            } else if (dynamic_cast<Chimchar*>(pokemonDoJogador) != nullptr) {
                static_cast<Chimchar*>(pokemonDoJogador)->atacarArranhao(*pokemonDoOponente);
            } else if (dynamic_cast<Piplup*>(pokemonDoJogador) != nullptr) {
                static_cast<Piplup*>(pokemonDoJogador)->atacarGolpe(*pokemonDoOponente);
            }
        }

        // Oponentes atacam aleatoriamente
        for (auto& oponente : oponentes) {
            if (oponente->estaVivo()) {
                if (rand() % 2 == 0) {
                    oponente->atacar(jogador1);
                } else {
                    oponente->atacar(jogador2);
                }
            }
        }

        turno++;
    }

    if (!jogador1.estaVivo() && !jogador2.estaVivo()) {
        cout << "\nTodos os seus Pokémons foram derrotados. Você perdeu a batalha!" << endl;
    } else if (!oponentes[0]->estaVivo() && !oponentes[1]->estaVivo()) {
        cout << "\nVocê derrotou todos os Pokémons do oponente. Você venceu a batalha!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    PokemonFogo charmander("Charmander", 52, 43, 39);
    PokemonAgua squirtle("Squirtle", 48, 65, 44);
    PokemonPlanta bulbasaur("Bulbasaur", 49, 49, 45);

    vector<Pokemon*> meusPokemons = { &charmander, &squirtle, &bulbasaur };

    Pikachu pikachu("Pikachu", 55, 40, 35);
    Chimchar chimchar("Chimchar", 58, 44, 39);
    Piplup piplup("Piplup", 51, 53, 40);

    vector<Pokemon*> oponentes = { &pikachu, &chimchar, &piplup };

    int escolha1, escolha2;
    cout << "Escolha dois Pokémons para a batalha:" << endl;
    cout << "1. Charmander" << endl;
    cout << "2. Squirtle" << endl;
    cout << "3. Bulbasaur" << endl;
    cout << "Escolha o primeiro Pokémon: ";
    cin >> escolha1;
    cout << "Escolha o segundo Pokémon: ";
    cin >> escolha2;

    Pokemon& meuPokemon1 = *meusPokemons[escolha1 - 1];
    Pokemon& meuPokemon2 = *meusPokemons[escolha2 - 1];

    batalha(meuPokemon1, meuPokemon2, oponentes);

    return 0;
}