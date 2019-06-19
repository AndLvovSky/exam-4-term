#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {

    int booksToGenerate = 15;

    int pauseBetweenSteps = 200;

private:

    Settings();

public:

    Settings(const Settings&) = delete;

    static Settings& get();

    void setBooksToGenerate(int booksToGenerate);

    void setPauseBetweenSteps(int pauseBetweenSteps);

    int getBooksToGenerate();

    int getPauseBetweenSteps();

};

#endif // SETTINGS_H
