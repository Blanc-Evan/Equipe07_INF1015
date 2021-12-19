#include "Salle.hpp"

void Salle::setDirections(const std::shared_ptr<Salle> nord, const std::shared_ptr<Salle> est, const std::shared_ptr<Salle> sud, const std::shared_ptr<Salle> ouest) {
    directions_.insert(std::pair<char, std::shared_ptr<Salle>>('N', nord));
    directions_.insert(std::pair<char, std::shared_ptr<Salle>>('E', est));
    directions_.insert(std::pair<char, std::shared_ptr<Salle>>('S', sud));
    directions_.insert(std::pair<char, std::shared_ptr<Salle>>('O', ouest));
}

void Salle::setDirection(const char& direction, const std::shared_ptr<Salle> s)
{
    directions_.insert(std::pair<char, std::shared_ptr<Salle>>(direction, s));
}

void Salle::ajouterObjet(std::shared_ptr<ObjetInterractif> objet)
{
    objets_.push_back(objet);
}

std::string Salle::getNom() const
{
    return nom_;
}

std::string Salle::getDescription() const
{
    return description_;
}

std::shared_ptr<Salle> Salle::getDirection(const char& direction) const {
    return directions_.at(direction);
}

std::string Salle::look() const {
    std::string str = this->description_;
    if (getDirection('N') != nullptr) str += directions_.at('N')->nom_ += " est au Nord (N) \n";
    if (getDirection('E') != nullptr) str += directions_.at('E')->nom_ += " est à l'Est (E) \n";
    if (getDirection('S') != nullptr) str += directions_.at('S')->nom_ += " est au Sud (S) \n";
    if (getDirection('O') != nullptr) str += directions_.at('O')->nom_ += " est à l'Ouest (O) \n";

    for (auto objet : objets_)
        str += objet->nom_ + "\n";

    return str;
}