#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Pokemon {
protected:
    std::string nome;
    int ataque;
    int defesa;
    int hp;

public:
    Pokemon(std::string nome, int ataque, int defesa, int hp);
    virtual ~Pokemon() {}

    virtual void atacar(Pokemon& outroPokemon) = 0;

    void defender(int dano);

    bool estaVivo() const;

    std::string getNome() const;

    void morrer();
};

class PokemonFogo : public Pokemon {
public:
    PokemonFogo(std::string nome, int ataque, int defesa, int hp);

    void atacar(Pokemon& outroPokemon) override;

    void atacarBrasas(Pokemon& outroPokemon);
};

class PokemonAgua : public Pokemon {
public:
    PokemonAgua(std::string nome, int ataque, int defesa, int hp);

    void atacar(Pokemon& outroPokemon) override;

    void atacarHidroBomba(Pokemon& outroPokemon);
};

class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(std::string nome, int ataque, int defesa, int hp);

    void atacar(Pokemon& outroPokemon) override;

    void atacarFolhaNavalha(Pokemon& outroPokemon);
};

class Pikachu : public Pokemon {
public:
    Pikachu(std::string nome, int ataque, int defesa, int hp);

    void atacarRaio();

    void atacarChoque();

    void atacar(Pokemon& outroPokemon) override;
};

class Chimchar : public Pokemon {
public:
    Chimchar(std::string nome, int ataque, int defesa, int hp);

    void atacarChama();

    void atacarArranhao();

    void atacar(Pokemon& outroPokemon) override;
};

class Piplup : public Pokemon {
public:
    Piplup(std::string nome, int ataque, int defesa, int hp);

    void atacarJato();

    void atacarGolpe();

    void atacar(Pokemon& outroPokemon) override;
};

#endif // POKEMON_H
