#ifndef H_CLASS_ASSETSTORE
#define H_CLASS_ASSETSTORE

#include <unordered_map>
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

    // image getters
    static bool imageExists (const std::string&);
    static std::shared_ptr<sf::Image> getImage (const std::string&);

    // image setters
    template<typename ...T>
    static std::shared_ptr<sf::Image> createImage (const std::string& key, T&&... args) {
        if (registerImage(key, std::make_shared<sf::Image>(std::forward<T>(args)...))) {
            return getImage(key);
        } else {
            return nullptr;
        }
    }
    static bool registerImage (const std::string&, sf::Image*);
    static bool registerImage (const std::string&, std::shared_ptr<sf::Image>);
    static void deleteImage (const std::string&);

    // sound getters
    static bool soundExists (const std::string&);
    static std::shared_ptr<sf::Sound> getSound (const std::string&);

    // sound setters
    template<typename ...T>
    static std::shared_ptr<sf::Sound> createSound (const std::string& key, T&&... args) {
        if (registerSound(key, std::make_shared<sf::Sound>(std::forward(args)...))) {
            return getSound(key);
        } else {
            return nullptr;
        }
    }
    static bool registerSound (const std::string&, sf::Sound*);
    static bool registerSound (const std::string&, std::shared_ptr<sf::Sound>);
    static void deleteSound (const std::string&);

    // font getters
    static bool fontExists (const std::string&);
    static std::shared_ptr<sf::Font> getFont (const std::string&);

    // font setters
    template<typename ...T>
    static std::shared_ptr<sf::Font> createFont (const std::string& key, T&&... args) {
        if (registerFont(key, std::make_shared<sf::Font>(std::forward(args)...))) {
            return getFont(key);
        } else {
            return nullptr;
        }
    }
    static bool registerFont (const std::string&, sf::Font*);
    static bool registerFont (const std::string&, std::shared_ptr<sf::Font>);
    static void deleteFont (const std::string&);

private:

    static std::unordered_map<std::string, std::shared_ptr<sf::Image>> m_images;
    static std::unordered_map<std::string, std::shared_ptr<sf::Sound>> m_sounds;
    static std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;

};

#endif
