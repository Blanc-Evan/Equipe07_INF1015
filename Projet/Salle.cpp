#include "Salle.hpp"

void Salle::setDirections(const std::shared_ptr<Salle> nord, const std::shared_ptr<Salle> est, const std::shared_ptr<Salle> sud, const std::shared_ptr<Salle> ouest) {
    directions.insert(std::pair<char, std::shared_ptr<Salle>>('N', nord));
    directions.insert(std::pair<char, std::shared_ptr<Salle>>('E', est));
    directions.insert(std::pair<char, std::shared_ptr<Salle>>('S', sud));
    directions.insert(std::pair<char, std::shared_ptr<Salle>>('O', ouest));
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
    return directions.at(direction);
}

std::string Salle::look() const {
    std::string str = this->description_;
    if (getDirection('N') != nullptr) str += directions.at('N')->nom_ += " est au Nord (N) \n";
    if (getDirection('E') != nullptr) str += directions.at('E')->nom_ += " est à l'Est (E) \n";
    if (getDirection('S') != nullptr) str += directions.at('S')->nom_ += " est au Sud (S) \n";
    if (getDirection('O') != nullptr) str += directions.at('O')->nom_ += " est à l'Ouest (O) \n";

    return str;
}
