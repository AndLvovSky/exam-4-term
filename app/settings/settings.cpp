#include "settings.h"

Settings::Settings() {}

Settings& Settings::get() {
    static Settings instance;
    return instance;
}

void Settings::setBooksToGenerate(int booksToGenerate) {
    this->booksToGenerate = booksToGenerate;
}

void Settings::setPauseBetweenSteps(int pauseBetweenSteps) {
    this->pauseBetweenSteps = pauseBetweenSteps;
}

int Settings::getBooksToGenerate() {
    return booksToGenerate;
}

int Settings::getPauseBetweenSteps() {
    return pauseBetweenSteps;
}
