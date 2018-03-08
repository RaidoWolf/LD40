#ifndef H_CLASS_ASSETSTORE
#define H_CLASS_ASSETSTORE

#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetStore {

public:

    AssetStore () = delete; // static only
    ~AssetStore () = delete;

    AssetStore (AssetStore&&) = delete;
    AssetStore& operator = (AssetStore&&) = delete;

    AssetStore (const AssetStore&) = delete;
    AssetStore& operator = (const AssetStore&) = delete;

    static bool imageExists (std::string);
    static std::shared_ptr<sf::Image> getImage (std::string);
    static bool soundExists (std::string);
    static std::shared_ptr<sf::Sound> getSound (std::string);
    static bool fontExists (std::string);
    static std::shared_ptr<sf::Font> getFont (std::string);

    static bool registerImage (std::string, sf::Image*);
    static void deleteImage (std::string);
    static bool registerSound (std::string, sf::Sound*);
    static void deleteSound (std::string);
    static bool registerFont (std::string, sf::Font*);
    static void deleteFont (std::string);

private:

    static std::map<std::string, std::shared_ptr<sf::Image>> m_images;
    static std::map<std::string, std::shared_ptr<sf::Sound>> m_sounds;
    static std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;

};

#endif
