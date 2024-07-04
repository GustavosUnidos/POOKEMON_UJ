#include "Pokemon.h"

Pokemon::Pokemon(std::string nome, int ataque, int defesa, int hp)
    : nome(nome), ataque(ataque), defesa(defesa), hp(hp) {}

void Pokemon::defender(int dano) {
    int danoRecebido = std::max(0, dano - defesa);
    hp -= danoRecebido;
    std::cout << nome << " recebeu " << danoRecebido << " de dano! HP restante: " << hp << std::endl;
   
    if (hp <= 0) {
        morrer();
    }
}

bool Pokemon::estaVivo() const {
    return hp > 0;
}

std::string Pokemon::getNome() const {
    return nome;
}

void Pokemon::morrer() {
    std::cout << nome << " foi derrotado!" << std::endl;
    // Aqui você pode adicionar qualquer ação adicional quando o Pokémon morrer
}

PokemonFogo::PokemonFogo(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void PokemonFogo::atacar(Pokemon& outroPokemon) {
    std::cout << nome << " usa Ataque de Fogo!" << std::endl;
    int dano = ataque + (rand() % 11) + 5;
    outroPokemon.defender(dano);
}

void PokemonFogo::atacarBrasas(Pokemon& outroPokemon) {
    std::cout << nome << " usa Brasas!" << std::endl;
    int dano = ataque + (rand() % 8) + 3;
    outroPokemon.defender(dano);
}

PokemonAgua::PokemonAgua(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void PokemonAgua::atacar(Pokemon& outroPokemon) {
    std::cout << nome << " usa Ataque de Água!" << std::endl;
    int dano = ataque + (rand() % 10) + 3;
    outroPokemon.defender(dano);
}

void PokemonAgua::atacarHidroBomba(Pokemon& outroPokemon) {
    std::cout << nome << " usa Hidro Bomba!" << std::endl;
    int dano = ataque + (rand() % 12) + 4;
    outroPokemon.defender(dano);
}

PokemonPlanta::PokemonPlanta(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void PokemonPlanta::atacar(Pokemon& outroPokemon) {
    std::cout << nome << " usa Ataque de Planta!" << std::endl;
    int dano = ataque + (rand() % 11) + 4;
    outroPokemon.defender(dano);
}

void PokemonPlanta::atacarFolhaNavalha(Pokemon& outroPokemon) {
    std::cout << nome << " usa Folha Navalha!" << std::endl;
    int dano = ataque + (rand() % 10) + 3;
    outroPokemon.defender(dano);
}

Pikachu::Pikachu(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void Pikachu::atacarRaio() {
    std::cout << nome << " usa Raio!" << std::endl;
    int dano = ataque + (rand() % 10) + 3;
    hp -= dano; // Pikachu ataca diretamente no HP
    std::cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << std::endl;
   
    if (hp <= 0) {
        morrer();
    }
}

void Pikachu::atacarChoque() {
    std::cout << nome << " usa Choque!" << std::endl;
    int dano = ataque + (rand() % 8) + 2;
    hp -= dano; // Pikachu ataca diretamente no HP
    std::cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << std::endl;
   
    if (hp <= 0) {
        morrer();
    }
}

void Pikachu::atacar(Pokemon& outroPokemon) {
    std::cout << nome << " usa Ataque Normal!" << std::endl;
    int dano = ataque + (rand() % 6) + 1;
    outroPokemon.defender(dano);
}

Chimchar::Chimchar(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void Chimchar::atacarChama() {
    std::cout << nome << " usa Chama!" << std::endl;
    int dano = ataque + (rand() % 9) + 3;
    hp -= dano; // Chimchar ataca diretamente no HP
    std::cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << std::endl;
   
    if (hp <= 0) {
        morrer();
    }
}

void Chimchar::atacarArranhao() {
    std::cout << nome << " usa Arranhão!" << std::endl;
    int dano = ataque + (rand() % 7) + 2;
    hp -= dano; // Chimchar ataca diretamente no HP
    std::cout << "Oponente recebeu " << dano << " de dano! HP restante: " << hp << std::endl;
   
    if (hp <= 0) {
        morrer();
    }
}

void Chimchar::atacar(Pokemon& outroPokemon) {
    std::cout << nome << " usa Ataque Normal!" << std::endl;
    int dano = ataque + (rand() % 6) + 1;
    outroPokemon.defender(dano);
}

Piplup::Piplup(std::string nome, int ataque, int defesa, int hp)
    : Pokemon(nome, ataque, defesa, hp) {}

void Piplup::atacarJato() {
    std::cout <<
