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
        cout << nome << " recebeu " << danoRecebido << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
    }

    bool estaVivo() const {
        return hp > 0;
    }

    string getNome() const {
        return nome;
    }

    void morrer() {
        cout << nome << " foi derrotado!" << endl;
        // Aqui você pode adicionar qualquer ação adicional quando o Pokémon morrer
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

// Novos Pokemons adicionados: Pikachu, Chimchar, Piplup

class Pikachu : public Pokemon {
public:
    Pikachu(string nome, int ataque, int defesa, int hp)
        : Pokemon(nome, ataque, defesa, hp) {}

    void atacarRaio() {
        cout << nome << " usa Raio!" << endl;
        int dano = ataque + (rand() % 10) + 3;
        hp -= dano; // Pikachu ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
    }

    void atacarChoque() {
        cout << nome << " usa Choque!" << endl;
        int dano = ataque + (rand() % 8) + 2;
        hp -= dano; // Pikachu ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
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

    void atacarChama() {
        cout << nome << " usa Chama!" << endl;
        int dano = ataque + (rand() % 9) + 3;
        hp -= dano; // Chimchar ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
    }

    void atacarArranhao() {
        cout << nome << " usa Arranhão!" << endl;
        int dano = ataque + (rand() % 7) + 2;
        hp -= dano; // Chimchar ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
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

    void atacarJato() {
        cout << nome << " usa Jato!" << endl;
        int dano = ataque + (rand() % 8) + 3;
        hp -= dano; // Piplup ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
    }

    void atacarGolpe() {
        cout << nome << " usa Golpe!" << endl;
        int dano = ataque + (rand() % 6) + 2;
        hp -= dano; // Piplup ataca diretamente no HP
        cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << endl;
        
        if (hp <= 0) {
            morrer();
        }
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
                static_cast<Pikachu*>(pokemonDoJogador)->atacarRaio();
            } else if (dynamic_cast<Chimchar*>(pokemonDoJogador) != nullptr) {
                static_cast<Chimchar*>(pokemonDoJogador)->atacarChama();
            } else if (dynamic_cast<Piplup*>(pokemonDoJogador) != nullptr) {
                static_cast<Piplup*>(pokemonDoJogador)->atacarJato();
            }
        } else {
            cout << "Escolha inválida. Perdeu o turno." << endl;
        }

        // Oponente ataca
        if (pokemonDoOponente->estaVivo()) {
            int escolhaAtaqueOponente = 1 + rand() % 2;

            if (escolhaAtaqueOponente == 1) {
                pokemonDoOponente->atacar(*pokemonDoJogador);
            } else if (escolhaAtaqueOponente == 2) {
                if (dynamic_cast<PokemonFogo*>(pokemonDoOponente) != nullptr) {
                    static_cast<PokemonFogo*>(pokemonDoOponente)->atacarBrasas(*pokemonDoJogador);
                } else if (dynamic_cast<PokemonAgua*>(pokemonDoOponente) != nullptr) {
                    static_cast<PokemonAgua*>(pokemonDoOponente)->atacarHidroBomba(*pokemonDoJogador);
                } else if (dynamic_cast<PokemonPlanta*>(pokemonDoOponente) != nullptr) {
                    static_cast<PokemonPlanta*>(pokemonDoOponente)->atacarFolhaNavalha(*pokemonDoJogador);
                } else if (dynamic_cast<Pikachu*>(pokemonDoOponente) != nullptr) {
                    static_cast<Pikachu*>(pokemonDoOponente)->atacarRaio();
                } else if (dynamic_cast<Chimchar*>(pokemonDoOponente) != nullptr) {
                    static_cast<Chimchar*>(pokemonDoOponente)->atacarChama();
                } else if (dynamic_cast<Piplup*>(pokemonDoOponente) != nullptr) {
                    static_cast<Piplup*>(pokemonDoOponente)->atacarJato();
                }
            }
        }

        turno++;
    }

    if (jogador1.estaVivo() || jogador2.estaVivo()) {
        cout << "\nVocê venceu a batalha!" << endl;
    } else {
        cout << "\nVocê perdeu a batalha!" << endl;
    }
}

void menu() {
    srand(time(0));

    cout << "Bem-vindo à Batalha Pokémon!" << endl;
    cout << "Escolha seus dois Pokémon:" << endl;
    cout << "1. Charmander (Fogo)" << endl;
    cout << "2. Squirtle (Água)" << endl;
    cout << "3. Bulbasaur (Planta)" << endl;
    cout << "4. Pikachu (Elétrico)" << endl;
    cout << "5. Chimchar (Fogo)" << endl;
    cout << "6. Piplup (Água)" << endl;

    int escolha1, escolha2;
    cout << "Escolha o primeiro Pokémon: ";
    cin >> escolha1;
    cout << "Escolha o segundo Pokémon: ";
    cin >> escolha2;

    Pokemon* jogador1;
    Pokemon* jogador2;
    switch (escolha1) {
        case 1:
            jogador1 = new PokemonFogo("Charmander", 20, 10, 100);
            break;
        case 2:
            jogador1 = new PokemonAgua("Squirtle", 18, 12, 100);
            break;
        case 3:
            jogador1 = new PokemonPlanta("Bulbasaur", 19, 11, 100);
            break;
        case 4:
            jogador1 = new Pikachu("Pikachu", 18, 8, 100);
            break;
        case 5:
            jogador1 = new Chimchar("Chimchar", 21, 9, 100);
            break;
        case 6:
            jogador1 = new Piplup("Piplup", 19, 10, 100);
            break;
        default:
            cout << "Escolha inválida, selecionando Charmander por padrão." << endl;
            jogador1 = new PokemonFogo("Charmander", 20, 10, 100);
            break;
    }

    switch (escolha2) {
        case 1:
            jogador2 = new PokemonFogo("Charmander", 20, 10, 100);
            break;
        case 2:
            jogador2 = new PokemonAgua("Squirtle", 18, 12, 100);
            break;
        case 3:
            jogador2 = new PokemonPlanta("Bulbasaur", 19, 11, 100);
            break;
        case 4:
            jogador2 = new Pikachu("Pikachu", 18, 8, 100);
            break;
        case 5:
            jogador2 = new Chimchar("Chimchar", 21, 9, 100);
            break;
        case 6:
            jogador2 = new Piplup("Piplup", 19, 10, 100);
            break;
        default:
            cout << "Escolha inválida, selecionando Charmander por padrão." << endl;
            jogador2 = new PokemonFogo("Charmander", 20, 10, 100);
            break;
    }

    // Adicionando dois pokemons para o oponente
    vector<Pokemon*> oponentes;
    int escolhaOponente1 = rand() % 3;
    int escolhaOponente2 = (escolhaOponente1 + 1) % 3; // Evita escolher o mesmo que o primeiro

    switch (escolhaOponente1) {
        case 0:
            oponentes.push_back(new PokemonFogo("Charizard", 22, 12, 120));
            break;
        case 1:
            oponentes.push_back(new PokemonAgua("Blastoise", 21, 14, 120));
            break;
        case 2:
            oponentes.push_back(new PokemonPlanta("Venusaur", 23, 11, 120));
            break;
    }

    switch (escolhaOponente2) {
        case 0:
            oponentes.push_back(new PokemonFogo("Charizard", 22, 12, 120));
            break;
        case 1:
            oponentes.push_back(new PokemonAgua("Blastoise", 21, 14, 120));
            break;
        case 2:
            oponentes.push_back(new PokemonPlanta("Venusaur", 23, 11, 120));
            break;
    }

    // Inicia a batalha
    batalha(*jogador1, *jogador2, oponentes);

    // Liberar memória dos Pokémons alocados
    delete jogador1;
    delete jogador2;
    for (Pokemon* oponente : oponentes) {
        delete oponente;
    }
}

int main() {
    menu();
    return 0;
}