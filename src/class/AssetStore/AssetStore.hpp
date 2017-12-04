#ifndef H_CLASS_ASSETSTORE
#define H_CLASS_ASSETSTORE

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetStore {

public:

    static bool imageExists (std::string);
    static sf::Image* getImage (std::string);
    static bool soundExists (std::string);
    static sf::Sound* getSound (std::string);
    static bool fontExists (std::string);
    static sf::Font* getFont (std::string);

    static bool registerImage (std::string, sf::Image*);
    static void deleteImage (std::string);
    static bool registerSound (std::string, sf::Sound*);
    static void deleteSound (std::string);
    static bool registerFont (std::string, sf::Font*);
    static void deleteFont (std::string);

private:

    AssetStore () = delete;

    static std::map<std::string, sf::Image*> m_images;
    static std::map<std::string, sf::Sound*> m_sounds;
    static std::map<std::string, sf::Font*> m_fonts;

};

#endif
