///This is needed to use the count and fill functions.
#include<algorithm>

///This is needed to use the size_t and ptrdiff_t integral types.
#include<cstddef>

///This is needed to use rand() and srand() functions.
#include<cstdlib>

///This is needed to use time objects provided by the C++ standard library.
#include<ctime>

///This is needed to use string stream objects.
#include<sstream>

///This is needed to use standard exceptions provided by the C++ standard library.
#include<stdexcept>

///This is needed to use string objects.
#include<string>

///This is needed to use vector objects.
#include<vector>

///This is needed to use/manipulate audio provided by the SFML third party API.
#include<SFML/Audio.hpp>

///This is needed to use/manipulate graphic objects provided by the SFML third party API.
#include<SFML/Graphics.hpp>

///This is needed to use/manipulate system objects like speed and time provided by the SFML third party API.
#include<SFML/System.hpp>

///This function sets up the attributes for the rocket object for the game.
void setRocket(bool& rocketDestroyed, sf::Sprite& rocketSprite, sf::Texture& rocketTexture, const std::string& rocketImageLocation)
{
    ///This checks to see if the texture successfully loaded from the file location.
    if(!rocketTexture.loadFromFile(rocketImageLocation))
    {
        ///If the texture was not successfully loaded from the file location,
        ///then this checks to see if a texture can be created from a set of pixels.
        if(!rocketTexture.create(50, 50))
        {
            ///If the texture cannot be created from a set of pixels,
            ///then the rocket cannot be created at all and an exception is thrown, abandoning the game.
            throw std::runtime_error("Fatal Error: Creation of rocket object failed. Abandoning Space Fighter Awesome.");
        }

        ///The pixels are in RGBA format. That is why we multiply the dimensions by four.
        sf::Uint8 rocketPixels[50*50*4];

        ///Here we load the pixels with RGBA numbers that amount to a red-colored texture.
        for(size_t width=0; width<50; ++width)
        {
            for(size_t height=0; height<50; ++height)
            {
                ///This is the R (Red) in RGBA.
                rocketPixels[(width+height*50)*4]=255;

                ///This is the G (Green) in RGBA.
                rocketPixels[(width+height*50)*4+1]=0;

                ///This is the B (Blue) in RGBA.
                rocketPixels[(width+height*50)*4+2]=0;

                ///This is the A (Alpha) in RGBA.
                rocketPixels[(width+height*50)*4+3]=255;
            }
        }

        ///Now we update the texture for the rocket object with the pixels we created.
        rocketTexture.update(rocketPixels);

        ///Now we smooth the texture out to make pixel boundaries less visible.
        rocketTexture.setSmooth(true);

        ///Now we set the texture for the rocket's sprite to be the texture we previously created.
        rocketSprite.setTexture(rocketTexture);

        ///Now we scale the rocket to fit the game screen appropriately.
        rocketSprite.setScale(0.85, 0.85);

        ///We set up the variable that keeps track of whether the rocket object is destroyed or not.
        rocketDestroyed=false;

        ///We finished setting up the rocket and return from the function.
        return;
    }

    ///We set up the variable that keeps track of whether the rocket object is destroyed or not.
    rocketDestroyed=false;

    ///Now we smooth the texture out to make pixel boundaries less visible.
    rocketTexture.setSmooth(true);

    ///Now we set the texture for the rocket's sprite to be the texture we previously created.
    rocketSprite.setTexture(rocketTexture);

    ///Now we scale the rocket to fit the game screen appropriately.
    rocketSprite.setScale(0.070, 0.070);
}

///This function sets up the attributes for the missile objects for the game.
void setMissiles(size_t& firedMissileCount, std::vector<bool>& missilesFired, std::vector<sf::Sprite>& missileSprites, std::vector<sf::Texture>& missileTextures, const std::string& missileImageLocation, size_t desiredMissileCount=20)
{
    ///We set the amount of missiles fired thus far to be zero since the game has not started by this point.
    firedMissileCount=0;

    ///Here we resize the state, sprite, and texture vectors for the missile objects appropriately.
    missilesFired.resize(desiredMissileCount);
    missileSprites.resize(desiredMissileCount);
    missileTextures.resize(desiredMissileCount);

    ///Now we set up the missile objects appropriately.
    for(size_t index=0; index<desiredMissileCount; ++index)
    {
        ///This checks to see if the texture for the current missile object successfully loaded from the file location.
        if(!missileTextures[index].loadFromFile(missileImageLocation))
        {
            ///If the texture for the current missile object was not successfully loaded from the file location,
            ///then this checks to see if a texture for the current missile object can be created from a set of pixels.
            if(!missileTextures[index].create(25, 25))
            {
                ///If the texture for the current missile object cannot be created from a set of pixels,
                ///then an exception is thrown, abandoning the game since one cannot work with an empty texture per say.
                throw std::runtime_error("Fatal Error: Creation of missile objects failed. Abandoning Space Fighter Awesome.");
            }

            ///The pixels are in RGBA format. That is why we multiply the dimensions by four.
            sf::Uint8 missilePixels[25*25*4];

            ///Here we load the pixels with RGBA numbers that amount to a blue-like-colored texture.
            for(size_t width=0; width<25; ++width)
            {
                for(size_t height=0; height<25; ++height)
                {
                    ///This is the R (Red) in RGBA.
                    missilePixels[(width+height*25)*4]=0;

                    ///This is the G (Green) in RGBA.
                    missilePixels[(width+height*25)*4+1]=7;

                    ///This is the B (Blue) in RGBA.
                    missilePixels[(width+height*25)*4+2]=255;

                    ///This is the A (Alpha) in RGBA.
                    missilePixels[(width+height*25)*4+3]=255;
                }
            }

            ///Now we update the texture for the current missile object with the pixels we created.
            missileTextures[index].update(missilePixels);

            ///Now we smooth the texture out to make pixel boundaries less visible.
            missileTextures[index].setSmooth(true);

            ///Now we set the texture for the current missile's sprite to be the texture we previously created.
            missileSprites[index].setTexture(missileTextures[index]);

            ///Now we scale the current missile object to fit the game screen appropriately.
            missileSprites[index].setScale(0.50, 0.50);

            ///We set up the variable that keeps track of whether the current missile object being indexed is destroyed or not.
            missilesFired[index]=false;

            ///We go to the next iteration of the loop to cover all the missile objects.
            continue;
        }

        ///Now we smooth the texture out to make pixel boundaries less visible.
        missileTextures[index].setSmooth(true);

        ///Now we set the texture for the current missile's sprite to be the texture we previously created.
        missileSprites[index].setTexture(missileTextures[index]);

        ///Now we scale the current missile object to fit the game screen appropriately.
        missileSprites[index].setScale(0.050, 0.050);

        ///We set up the variable that keeps track of whether the current missile object being indexed is fired or not.
        missilesFired[index]=false;
    }
}

///This function sets up the attributes for the obstacle objects for the game.
void setObstacles(std::vector<bool>& obstaclesDestroyed, std::vector<sf::Sprite>& obstacleSprites, std::vector<sf::Texture>& obstacleTextures, const std::string& obstacleImageLocation, size_t desiredObstacleCount=20)
{
    ///Here we resize the state, sprite, and texture vectors for the obstacle objects appropriately.
    obstaclesDestroyed.resize(desiredObstacleCount);
    obstacleSprites.resize(desiredObstacleCount);
    obstacleTextures.resize(desiredObstacleCount);

    ///Now we set up the obstacle objects appropriately.
    for(size_t index=0; index<desiredObstacleCount; ++index)
    {
        ///This checks to see if the texture for the current obstacle object successfully loaded from the file location.
        if(!obstacleTextures[index].loadFromFile(obstacleImageLocation))
        {
            ///If the texture for the current obstacle object was not successfully loaded from the file location,
            ///then this checks to see if a texture for the current obstacle object can be created from a set of pixels.
            if(!obstacleTextures[index].create(30, 30))
            {
                ///If the texture for the current obstacle object cannot be created from a set of pixels,
                ///then an exception is thrown, abandoning the game since one cannot work with an empty texture per say.
                throw std::runtime_error("Fatal Error: Creation of obstacle objects failed. Abandoning Space Fighter Awesome.");
            }

            ///The pixels are in RGBA format. That is why we multiply the dimensions by four.
            sf::Uint8 obstaclePixels[30*30*4];

            ///Here we load the pixels with RGBA numbers that amount to a orange-like-colored texture.
            for(size_t width=0; width<30; ++width)
            {
                for(size_t height=0; height<30; ++height)
                {
                    ///This is the R (Red) in RGBA.
                    obstaclePixels[(width+height*30)*4]=255;

                    ///This is the G (Green) in RGBA.
                    obstaclePixels[(width+height*30)*4+1]=137;

                    ///This is the B (Blue) in RGBA.
                    obstaclePixels[(width+height*30)*4+2]=0;

                    ///This is the A (Alpha) in RGBA.
                    obstaclePixels[(width+height*30)*4+3]=255;
                }
            }

            ///Now we update the texture for the current obstacle object with the pixels we created.
            obstacleTextures[index].update(obstaclePixels);

            ///Now we smooth the texture out to make pixel boundaries less visible.
            obstacleTextures[index].setSmooth(true);

            ///Now we set the texture for the current obstacle's sprite to be the texture we previously created.
            obstacleSprites[index].setTexture(obstacleTextures[index]);

            ///Now we scale the current obstacle object to fit the game screen appropriately.
            obstacleSprites[index].setScale(0.90, 0.90);

            ///We set up the variable that keeps track of whether the current obstacle object being indexed is destroyed or not.
            obstaclesDestroyed[index]=false;

            ///We go to the next iteration of the loop to cover all the obstacle objects.
            continue;
        }

        ///Now we smooth the texture out to make pixel boundaries less visible.
        obstacleTextures[index].setSmooth(true);

        ///Now we set the texture for the current obstacle's sprite to be the texture we previously created.
        obstacleSprites[index].setTexture(obstacleTextures[index]);

        ///Now we scale the current obstacle object to fit the game screen appropriately.
        obstacleSprites[index].setScale(0.20, 0.20);

        ///We set up the variable that keeps track of whether the current obstacle object being indexed is fired or not.
        obstaclesDestroyed[index]=false;
    }
}

///This function sets up the attributes for the health pickup objects for the game.
void setHealthPickup(size_t& healthPickupDuration, sf::Sprite& healthPickupSprite, sf::Texture& healthPickupTexture, const std::string& healthImageLocation)
{
    ///This checks to see if the texture successfully loaded from the file location.
    if(!healthPickupTexture.loadFromFile(healthImageLocation))
    {
        ///If the texture for the health pickup object was not successfully loaded from the file location,
        ///then this checks to see if a texture for the health pickup object can be created from a set of pixels.
        if(!healthPickupTexture.create(20, 20))
        {
            ///If the texture for the health pickup object cannot be created from a set of pixels,
            ///then an exception is thrown, abandoning the game since one cannot work with an empty texture per say.
            throw std::runtime_error("Fatal Error: Creation of health pickup object failed. Abandoning Space Fighter Awesome.");
        }

        ///The pixels are in RGBA format. That is why we multiply the dimensions by four.
        sf::Uint8 healthPickupPixels[20*20*4];

        ///Here we load the pixels with RGBA numbers that amount to a green-like-colored texture.
        for(size_t width=0; width<20; ++width)
        {
            for(size_t height=0; height<20; ++height)
            {
                ///This is the R (Red) in RGBA.
                healthPickupPixels[(width+height*20)*4]=0;

                ///This is the G (Green) in RGBA.
                healthPickupPixels[(width+height*20)*4+1]=255;

                ///This is the B (Blue) in RGBA.
                healthPickupPixels[(width+height*20)*4+2]=77;

                ///This is the A (Alpha) in RGBA.
                healthPickupPixels[(width+height*20)*4+3]=255;
            }
        }

        ///Now we update the texture for the health pickup object with the pixels we created.
        healthPickupTexture.update(healthPickupPixels);

        ///Now we smooth the texture out to make pixel boundaries less visible.
        healthPickupTexture.setSmooth(true);

        ///Now we set the texture for the health pickup's sprite to be the texture we previously created.
        healthPickupSprite.setTexture(healthPickupTexture);

        ///Now we scale the health pickup to fit the game screen appropriately.
        healthPickupSprite.setScale(0.80, 0.80);

        ///We set up the variable that keeps track of how long the health pickup will show on the game screen.
        healthPickupDuration=static_cast<size_t>(rand())%1500;

        ///We finished setting up the health pickup and return from the function.
        return;
    }

    ///Now we smooth the texture out to make pixel boundaries less visible.
    healthPickupTexture.setSmooth(true);

    ///Now we set the texture for the health pickup's sprite to be the texture we previously created.
    healthPickupSprite.setTexture(healthPickupTexture);

    ///Now we scale the health pickup to fit the game screen appropriately.
    healthPickupSprite.setScale(0.050, 0.050);

    ///We set up the variable that keeps track of how long the health pickup will show on the game screen.
    healthPickupDuration=static_cast<size_t>(rand())%1500;
}

///This function sets up the attributes for the missile pickup objects for the game.
void setMissilePickup(size_t& missilePickupDuration, sf::Sprite& missilePickupSprite, sf::Texture& missilePickupTexture, const std::string& missilePickupImageLocation)
{
    ///This checks to see if the texture successfully loaded from the file location.
    if(!missilePickupTexture.loadFromFile(missilePickupImageLocation))
    {
        ///If the texture for the missile pickup object was not successfully loaded from the file location,
        ///then this checks to see if a texture for the missile pickup object can be created from a set of pixels.
        if(!missilePickupTexture.create(20, 20))
        {
            ///If the texture for the missile pickup object cannot be created from a set of pixels,
            ///then an exception is thrown, abandoning the game since one cannot work with an empty texture per say.
            throw std::runtime_error("Fatal Error: Creation of missile pickup object failed. Abandoning Space Fighter Awesome.");
        }

        ///The pixels are in RGBA format. That is why we multiply the dimensions by four.
        sf::Uint8 missilePickupPixels[20*20*4];

        ///Here we load the pixels with RGBA numbers that amount to a black-colored texture.
        for(size_t width=0; width<20; ++width)
        {
            for(size_t height=0; height<20; ++height)
            {
                ///This is the R (Red) in RGBA.
                missilePickupPixels[(width+height*20)*4]=0;

                ///This is the G (Green) in RGBA.
                missilePickupPixels[(width+height*20)*4+1]=0;

                ///This is the B (Blue) in RGBA.
                missilePickupPixels[(width+height*20)*4+2]=0;

                ///This is the A (Alpha) in RGBA.
                missilePickupPixels[(width+height*20)*4+3]=255;
            }
        }

        ///Now we update the texture for the missile pickup object with the pixels we created.
        missilePickupTexture.update(missilePickupPixels);

        ///Now we smooth the texture out to make pixel boundaries less visible.
        missilePickupTexture.setSmooth(true);

        ///Now we set the texture for the missile pickup's sprite to be the texture we previously created.
        missilePickupSprite.setTexture(missilePickupTexture);

        ///Now we scale the missile pickup to fit the game screen appropriately.
        missilePickupSprite.setScale(0.80, 0.80);

        ///We set up the variable that keeps track of how long the missile pickup will show on the game screen.
        missilePickupDuration=static_cast<size_t>(rand())%1500;

        ///We finished setting up the missile pickup and return from the function.
        return;
    }

    ///Now we smooth the texture out to make pixel boundaries less visible.
    missilePickupTexture.setSmooth(true);

    ///Now we set the texture for the missile pickup's sprite to be the texture we previously created.
    missilePickupSprite.setTexture(missilePickupTexture);

    ///Now we scale the missile pickup to fit the game screen appropriately.
    missilePickupSprite.setScale(0.25, 0.25);

    ///We set up the variable that keeps track of how long the missile pickup will show on the game screen.
    missilePickupDuration=static_cast<size_t>(rand())%1500;
}

///This function sets up the attributes for the sound for health pickup objects for the game.
void setHealthPickupSound(sf::Sound& healthPickupSound, sf::SoundBuffer& healthPickupSoundBuffer, const std::string& healthSoundLocation)
{
    ///This loads the sound data for health pickup objects into the sound buffer.
    ///We need the sound buffer in order to play the sound.
    healthPickupSoundBuffer.loadFromFile(healthSoundLocation);

    ///We set up the sound for the health pickup object using the sound buffer
    ///we previously loaded as its sound object's sound buffer.
    healthPickupSound.setBuffer(healthPickupSoundBuffer);
}

///This function sets up the attributes for the sound for missile pickup objects for the game.
void setMissilePickupSound(sf::Sound& missilePickupSound, sf::SoundBuffer& missilePickupSoundBuffer, const std::string& missilePickupSoundLocation)
{
    ///This loads the sound data for missile pickup objects into the sound buffer.
    ///We need the sound buffer in order to play the sound.
    missilePickupSoundBuffer.loadFromFile(missilePickupSoundLocation);

    ///We set up the sound for the missile pickup object using the sound buffer
    ///we previously loaded as its sound object's sound buffer.
    missilePickupSound.setBuffer(missilePickupSoundBuffer);
}

///This function sets up the attributes for the sound for missile objects for the game.
void setMissileSound(sf::Sound& missileSound, sf::SoundBuffer& missileSoundBuffer, const std::string& missileSoundLocation)
{
    ///This loads the sound data for missile objects into the sound buffer.
    ///We need the sound buffer in order to play the sound.
    missileSoundBuffer.loadFromFile(missileSoundLocation);

    ///We set up the sound for missile objects using the sound buffer
    ///we previously loaded as their sound object's sound buffer.
    missileSound.setBuffer(missileSoundBuffer);
}

///This function sets up the attributes for the sound for obstacle objects for the game.
void setObstacleSound(sf::Sound& obstacleSound, sf::SoundBuffer& obstacleSoundBuffer, const std::string& obstacleSoundLocation)
{
    ///This loads the sound data for obstacle objects into the sound buffer.
    ///We need the sound buffer in order to play the sound.
    obstacleSoundBuffer.loadFromFile(obstacleSoundLocation);

    ///We set up the sound for obstacle objects using the sound buffer
    ///we previously loaded as their sound object's sound buffer.
    obstacleSound.setBuffer(obstacleSoundBuffer);
}

///This function sets up the attributes for the sound for the rocket object for the game.
void setRocketSound(sf::Sound& rocketSound, sf::SoundBuffer& rocketSoundBuffer, const std::string& rocketSoundLocation)
{
    ///This loads the sound data for the rocket object into the sound buffer.
    ///We need the sound buffer in order to play the sound.
    rocketSoundBuffer.loadFromFile(rocketSoundLocation);

    ///We set up the sound for the rocket object using the sound buffer
    ///we previously loaded as its sound object's sound buffer.
    rocketSound.setBuffer(rocketSoundBuffer);
}

///This function sets up the attributes for the music for the start menu of the game.
void setPregameMusic(sf::Music& pregameMusic, const std::string& pregameMusicLocation)
{
    ///This opens the music data for the start menu for the game.
    ///Once the music data is opened, the data can be extracted in order to be played.
    pregameMusic.openFromFile(pregameMusicLocation);

    ///We set up the pregame music to be looped as long as the game's title screen shows.
    pregameMusic.setLoop(true);
}

///This function sets up the attributes for the music during game play.
void setBackgroundMusic(sf::Music& backgroundMusic, const std::string& backgroundMusicLocation)
{
    ///This opens the music data for the music to be played during game play.
    ///Once the music data is opened, the data can be extracted in order to be played.
    backgroundMusic.openFromFile(backgroundMusicLocation);

    ///We set the background music's volume to 20 as to not completely overpower the other sounds.
    backgroundMusic.setVolume(20);

    ///We set up the background music to be looped as long as the game is playing.
    backgroundMusic.setLoop(true);
}

///This function sets up the attributes for the music for the game over menu of the game.
void setPostgameMusic(sf::Music& postgameMusic, const std::string& postgameMusicLocation)
{
    ///This opens the music data for the game over menu of the game.
    ///Once the music data is opened, the data can be extracted in order to be played.
    postgameMusic.openFromFile(postgameMusicLocation);

    ///We set up the postgame music to be looped as long as the game's game-over screen shows.
    postgameMusic.setLoop(true);
}

///This function sets up the attributes for the health display that will show the rocket's current health on the game screen.
void setHealthDisplay(size_t& currentHealth, sf::Font& healthFont, sf::Text& healthText, const std::string& healthFontLocation, const sf::Color& desiredHealthColor=sf::Color::White, size_t desiredCharacterSize=50)
{
    ///We first set up the health that the player's rocket will start with.
    currentHealth=100;

    ///We load up the font from a file to be used for displaying the player's rocket health on the screen.
    healthFont.loadFromFile(healthFontLocation);

    ///We set the text that will display the rocket's current health's font to be the font we previously loaded.
    healthText.setFont(healthFont);

    ///We set the text that will display the rocket's current health's color to be the color we pass to this function.
    ///Note: The color is white by default, although one can pass their desired color to this function if they wish.
    healthText.setFillColor(desiredHealthColor);

    ///We set the text that will display the rocket's current health's character size to be the desired character size we pass to this function.
    ///Note: The character size is 50 is by default, although one can pass their desired character size to this function if they wish.
    healthText.setCharacterSize(desiredCharacterSize);

    ///We now put the current health in an output string stream.
    std::ostringstream currentHealthStringStream;
    currentHealthStringStream<<"HP: "<<currentHealth;

    ///We set up the text that will display the rocket's current health's string from the output string stream.
    healthText.setString(currentHealthStringStream.str());
}

///This function sets up the attributes for the score display that will show the player's current score on the game screen.
void setScoreDisplay(size_t& currentScore, sf::Font& scoreFont, sf::Text& scoreText, const std::string& scoreFontLocation, const sf::Color& desiredScoreColor=sf::Color::White, size_t desiredCharacterSize=50)
{
    ///We first set up the score that the player will start with.
    currentScore=0;

    ///We load up the font from a file to be used for displaying the player's current score on the screen.
    scoreFont.loadFromFile(scoreFontLocation);

    ///We set the text that will display the player's current score's font to be the font we previously loaded.
    scoreText.setFont(scoreFont);

    ///We set the text that will display the player's current score's color to be the color we pass to this function.
    ///Note: The color is white by default, although one can pass their desired color to this function if they wish.
    scoreText.setFillColor(desiredScoreColor);

    ///We set the text that will display the player's current score's character size to be the desired character size we pass to this function.
    ///Note: The character size is 50 is by default, although one can pass their desired character size to this function if they wish.
    scoreText.setCharacterSize(desiredCharacterSize);

    ///We now put the current score in an output string stream.
    std::ostringstream currentScoreStringStream;
    currentScoreStringStream<<"Score: "<<currentScore;

    ///We set up the text that will display the player's current score's string from the output string stream.
    scoreText.setString(currentScoreStringStream.str());
}

///This function sets up the attributes for the pregame text that will show up on the pregame screen.
void setPregameText(sf::Font& pregameFont, sf::Text& pregameText, const std::string& pregameFontLocation, const sf::Color& desiredPregameColor=sf::Color::Yellow, size_t desiredCharacterSize=50)
{
    ///We load up the font from a file to be used for displaying the game's title and instructions on the pregame screen.
    pregameFont.loadFromFile(pregameFontLocation);

    ///We set the text that will display the game's title and instruction's font to be the font we previously loaded.
    pregameText.setFont(pregameFont);

    ///We set the text that will display the game's title and instruction's color to be the color we pass to this function.
    ///Note: The color is yellow by default, although one can pass their desired color to this function if they wish.
    pregameText.setFillColor(desiredPregameColor);

    ///We set the text that will display the game's title and instruction's character size to be the desired character size we pass to this function.
    ///Note: The character size is 50 is by default, although one can pass their desired character size to this function if they wish.
    pregameText.setCharacterSize(desiredCharacterSize);

    ///We set up the text that will display the game's title and instruction's string.
    pregameText.setString("Space Fighter Awesome!\n\nPress P to start the game.\n\nPress Q to quit the game.");
}

///This function sets up the attributes for the paused game text that will show up when the player pauses the game.
void setPausedgameText(sf::Font& pausedgameFont, sf::Text& pausedgameText, const std::string& pausedgameFontLocation, const sf::Color& desiredPausedgameColor=sf::Color::Yellow, size_t desiredCharacterSize=50)
{
    ///We load up the font from a file to be used for displaying the paused game text when the player pauses the game.
    pausedgameFont.loadFromFile(pausedgameFontLocation);

    ///We set the text that will display the paused game's text's font to be the font we previously loaded.
    pausedgameText.setFont(pausedgameFont);

    ///We set the text that will display the paused game's text's color to be the color we pass to this function.
    ///Note: The color is yellow by default, although one can pass their desired color to this function if they wish.
    pausedgameText.setFillColor(desiredPausedgameColor);

    ///We set the text that will display the paused game's text's character size to be the desired character size we pass to this function.
    ///Note: The character size is 50 is by default, although one can pass their desired character size to this function if they wish.
    pausedgameText.setCharacterSize(desiredCharacterSize);

    ///We set up the text that will display the paused game's text's string.
    pausedgameText.setString("\t\tPaused");
}

///This function sets up the attributes for the postgame text that will show up on the postgame screen.
void setPostgameText(sf::Font& postgameFont, sf::Text& postgameText, const std::string& postgameFontLocation, const sf::Color& desiredPostgameColor=sf::Color::Yellow, size_t desiredCharacterSize=50)
{
    ///We load up the font from a file to be used for displaying the game's game-over title and instructions on the postgame screen.
    postgameFont.loadFromFile(postgameFontLocation);

    ///We set the text that will display the game's game-over title and instruction's font to be the font we previously loaded.
    postgameText.setFont(postgameFont);

    ///We set the text that will display the game's game-over title and instruction's color to be the color we pass to this function.
    ///Note: The color is yellow by default, although one can pass their desired color to this function if they wish.
    postgameText.setFillColor(desiredPostgameColor);

    ///We set the text that will display the game's game-over title and instruction's character size to be the desired character size we pass to this function.
    ///Note: The character size is 50 is by default, although one can pass their desired character size to this function if they wish.
    postgameText.setCharacterSize(desiredCharacterSize);
}

///This function sets up the attributes that relate to the game screen.
void setGameWindow(size_t& gameWindowWidth, size_t& gameWindowHeight, sf::RenderWindow& gameWindow, sf::Sprite& backgroundSprite, sf::Texture& backgroundTexture, const std::string& backgroundImageLocation, const std::string& gameWindowTitle="Chuyun's Rocket Game!", size_t desiredGameWindowWidth=800, size_t desiredGameWindowHeight=800)
{
    ///We set up the variable that keeps track of the width of the game screen.
    gameWindowWidth=desiredGameWindowWidth;

    ///We set up the variable that keeps track of the height of the game screen.
    gameWindowHeight=desiredGameWindowHeight;

    ///We load the texture from the file location passed to this function.
    ///Note: If the texture could not be loaded from the file,
    ///the game screen's refresh color will be the game screen's background.
    backgroundTexture.loadFromFile(backgroundImageLocation, sf::IntRect(0, 0, desiredGameWindowWidth, desiredGameWindowHeight));

    ///Now we smooth the texture out to make pixel boundaries less visible.
    backgroundTexture.setSmooth(true);

    ///Now we set the texture for the game screen background's sprite to be the texture we previously created.
    backgroundSprite.setTexture(backgroundTexture);

    ///We create the game window using the desired game width, the desired game height, and the desired game window title.
    gameWindow.create(sf::VideoMode(desiredGameWindowWidth, desiredGameWindowHeight), gameWindowTitle);

    ///We set the game screen's frame rate to sync with the computer's natural frame rate.
    gameWindow.setVerticalSyncEnabled(true);
}

///This sets the initial positions of various game objects relative to the game screen
///right before the initial loading of the game.
void setInitialPositions(size_t gameWindowWidth, size_t gameWindowHeight, sf::Sprite& rocketSprite, sf::Sprite& healthPickupSprite, sf::Sprite& missilePickupSprite, sf::Text& healthText, sf::Text& scoreText, sf::Text& pregameText, sf::Text& pausedgameText)
{
    ///We set up the initial position of the sprite for the rocket object.
    rocketSprite.setPosition(gameWindowWidth/2, gameWindowHeight-2*rocketSprite.getGlobalBounds().height);

    ///We set up the initial position of the sprite for health pickup objects.
    healthPickupSprite.setPosition(static_cast<size_t>(rand())%static_cast<size_t>(gameWindowWidth-healthPickupSprite.getGlobalBounds().width), static_cast<size_t>(rand())%static_cast<size_t>(gameWindowHeight-healthPickupSprite.getGlobalBounds().height));

    ///We set up the initial position of the sprite for missile pickup objects.
    missilePickupSprite.setPosition(static_cast<size_t>(rand())%static_cast<size_t>(gameWindowWidth-missilePickupSprite.getGlobalBounds().width), static_cast<size_t>(rand())%static_cast<size_t>(gameWindowHeight-missilePickupSprite.getGlobalBounds().height));

    ///We set up the initial position of the text for the health display.
    healthText.setPosition(1, 1);

    ///We set up the initial position of the text for the score display.
    scoreText.setPosition(gameWindowWidth-scoreText.getGlobalBounds().width-10, 1);

    ///We set up the initial position of the text for the pregame's title and instructions.
    pregameText.setPosition(gameWindowWidth/7, gameWindowHeight/3);

    ///We set up the initial position of the text for when the player pauses the game.
    pausedgameText.setPosition(gameWindowWidth/4, gameWindowHeight/2);
}

///This function sets up technical aspects of the game such as the trigger for the game to pause.
void setGameTechnicals(size_t& gameStatus, bool& gamePaused)
{
    ///We set the game status to be 0, meaning the game will show the pregame screen.
    gameStatus=0;

    ///We set up the trigger to pause the game to be false, meaning the game will not be paused.
    gamePaused=false;
}

///This function updates the attributes pertaining to missiles that have been fired from the rocket.
void updateFiringMissiles(size_t firedMissileCount, std::vector<sf::Sprite>& missileSprites, std::vector<bool>& obstaclesDestroyed, const std::vector<sf::Sprite>& obstacleSprites, const sf::Time& elapsedTime, sf::Sound& obstacleSound, sf::RenderWindow& gameWindow, bool gamePaused)
{
    ///We now sequentially access all the missiles that have been fired from the rocket
    ///in order to update them appropriately.
    for(size_t missileIndex=0; missileIndex<firedMissileCount; ++missileIndex)
    {
        ///We draw the missile that is firing continuously to ensure
        ///correctness of the program.
        gameWindow.draw(missileSprites[missileIndex]);

        ///This if statement controls whether to show the firing missile depending if the
        ///game is paused or not.
        if(!gamePaused)
        {
            ///We move the missile vertically up due to being fired from the missile.
            missileSprites[missileIndex].move(0, -elapsedTime.asMilliseconds());

            ///Now we sequentially access all the obstacles to see if they collide with any fired missile
            ///in order to signal if they are destroyed.
            for(size_t obstacleIndex=0; obstacleIndex<obstacleSprites.size(); ++obstacleIndex)
            {
                ///This if statement checks if the obstacle has not already been destroyed before colliding with the missiles being fired.
                if(!obstaclesDestroyed[obstacleIndex]&&missileSprites[missileIndex].getGlobalBounds().intersects(obstacleSprites[obstacleIndex].getGlobalBounds()))
                {
                    ///If the firing missile collides with the obstacle, then the obstacle is destroyed.
                    ///This sound plays to notify the player of that fact.
                    obstacleSound.play();

                    ///After the obstacle is destroyed the obstacle's destroyed state is set.
                    obstaclesDestroyed[obstacleIndex]=true;
                }
            }
        }
    }
}

///This function updates the attributes pertaining to the game obstacles.
void updateObstacles(const sf::Sprite& rocketSprite, const std::vector<bool>& obstaclesDestroyed, std::vector<sf::Sprite>& obstacleSprites, const sf::Time& elapsedTime, size_t gameWindowWidth, size_t gameWindowHeight, sf::RenderWindow& gameWindow, bool gamePaused)
{
    ///We now sequentially access all the obstacles in order to update them appropriately.
    for(size_t obstacleIndex=0; obstacleIndex<obstacleSprites.size(); ++obstacleIndex)
    {
        ///We first check if the obstacle has not been destroyed yet.
        ///If the obstacle was previously destroyed, then there is no need to update it.
        if(!obstaclesDestroyed[obstacleIndex])
        {
            ///The game window draws the obstacle object as long as the
            ///obstacle object is not destroyed.
            gameWindow.draw(obstacleSprites[obstacleIndex]);

            ///This checks if the game is paused or not before updating the obstacle objects that are not destroyed.
            ///If the game is paused then we do not update the obstacles in terms of movement.
            if(!gamePaused)
            {
                ///We move the obstacle sprites randomly in relation to the game screen.
                obstacleSprites[obstacleIndex].move(static_cast<size_t>(rand())%static_cast<size_t>(gameWindowWidth-obstacleSprites[obstacleIndex].getGlobalBounds().width-rocketSprite.getGlobalBounds().width)*elapsedTime.asSeconds()/2, static_cast<size_t>(rand())%static_cast<size_t>(gameWindowHeight-obstacleSprites[obstacleIndex].getGlobalBounds().height-rocketSprite.getGlobalBounds().height)*elapsedTime.asSeconds()/2);

                ///We update the position of the obstacle if it manages to move out of bounds relative to the game screen.
                if(obstacleSprites[obstacleIndex].getPosition().x<=0||obstacleSprites[obstacleIndex].getPosition().x>=gameWindowWidth||obstacleSprites[obstacleIndex].getPosition().y<=0||obstacleSprites[obstacleIndex].getPosition().y>=gameWindowHeight)
                {
                    ///We reset the position of the current game obstacle being indexed.
                    obstacleSprites[obstacleIndex].setPosition(static_cast<size_t>(rand())%static_cast<size_t>(gameWindowWidth-obstacleSprites[obstacleIndex].getGlobalBounds().width-rocketSprite.getGlobalBounds().width), static_cast<size_t>(rand())%static_cast<size_t>(gameWindowHeight-obstacleSprites[obstacleIndex].getGlobalBounds().height-rocketSprite.getGlobalBounds().height));
                }
            }
        }
    }
}

///This function updates the variables pertaining to health pickup objects.
void updateHealthPickup(const sf::Sprite& rocketSprite, sf::Sprite& healthPickupSprite, sf::Sound& healthPickupSound, size_t& healthPickupDuration, size_t& currentHealth, sf::Text& healthText, size_t gameWindowWidth, size_t gameWindowHeight, sf::RenderWindow& gameWindow, bool gamePaused)
{
    ///If the health pickup duration is within a valid range,
    ///the game window draws the health pickup object.
    if(healthPickupDuration<1500)
    {
        ///We draw the health pickup sprite as long as the
        ///health pickup duration is within a valid range.
        gameWindow.draw(healthPickupSprite);
    }

    ///This checks to see if the game is paused or not in relation to the health pickup object.
    ///If the game is paused, then there is no need to update the health pickup object.
    if(!gamePaused)
    {
        ///This if statement covers the case where the health pickup duration
        ///is in a valid range that enables it to be shown on the game screen.
        if(healthPickupDuration<1500&&rocketSprite.getGlobalBounds().intersects(healthPickupSprite.getGlobalBounds()))
        {
            ///We set up the health pickup object's duration to be in all the valid ranges of whether
            ///the health pickup object will show or not.
            healthPickupDuration=static_cast<size_t>(rand())%3000;

            ///We change the position of the health pickup sprite to another position.
            healthPickupSprite.setPosition(static_cast<size_t>(rand())%gameWindowWidth, static_cast<size_t>(rand())%gameWindowHeight);

            ///We play the sound that notifies the player that they have picked up health.
            healthPickupSound.play();

            ///We increase the player's health after they pickup health.
            currentHealth+=10;

            ///This checks to see if the player's health is over the maximum allowed health
            ///after they pickup health.
            ///If it is over the maximum, we reset the health to its maximum of 100.
            if(currentHealth>100)
            {
                currentHealth=100;
            }

            ///We prepare an output string stream that will
            ///help in updating the player's current health.
            std::ostringstream currentHealthStringStream;
            currentHealthStringStream<<"HP: "<<currentHealth;

            ///We now update the text that will show the rocket's, i.e. player's, current health.
            healthText.setString(currentHealthStringStream.str());
        }

        ///This is the case where the pickup health duration reaches its boundary points
        ///of whether the health pickup object will show or not.
        else if(healthPickupDuration==0||healthPickupDuration==1500)
        {
            ///We set up the health pickup object's duration to be in all the valid ranges of whether
            ///the health pickup object will show or not.
            healthPickupDuration=static_cast<size_t>(rand())%3000;

            ///We change the position of the health pickup sprite to another position.
            healthPickupSprite.setPosition(static_cast<size_t>(rand())%gameWindowWidth, static_cast<size_t>(rand())%gameWindowHeight);
        }

        ///This is the case where we control how long
        ///the health pickup object will show or not.
        else
        {
            ///This checks whether the health pickup duration is equal to either boundary point
            ///so as to not keep decreasing it.
            if(healthPickupDuration!=0&&healthPickupDuration!=1500)
            {
                --healthPickupDuration;
            }
        }
    }
}

///This function updates the variables pertaining to missile pickup objects.
void updateMissilePickup(const sf::Sprite& rocketSprite, size_t& firedMissileCount, std::vector<bool>& missilesFired, size_t& missilePickupDuration, sf::Sprite& missilePickupSprite, sf::Sound& missilePickupSound, size_t gameWindowWidth, size_t gameWindowHeight, sf::RenderWindow& gameWindow, bool gamePaused)
{
    ///If the missile pickup duration is within a valid range,
    ///the game window draws the health pickup object.
    if(missilePickupDuration<1500)
    {
        ///We draw the missile pickup sprite as long as the
        ///missile pickup duration is within a valid range.
        gameWindow.draw(missilePickupSprite);
    }

    ///This checks to see if the game is paused or not in relation to the missile pickup object.
    ///If the game is paused, then there is no need to update the missile pickup object.
    if(!gamePaused)
    {
        ///This if statement covers the case where the missile pickup duration
        ///is in a valid range that enables it to be shown on the game screen.
        if(missilePickupDuration<1500&&rocketSprite.getGlobalBounds().intersects(missilePickupSprite.getGlobalBounds()))
        {
            ///We set up the missile pickup object's duration to be in all the valid ranges of whether
            ///the missile pickup object will show or not.
            missilePickupDuration=static_cast<size_t>(rand())%3000;

            ///We change the position of the missile pickup sprite to another position.
            missilePickupSprite.setPosition(static_cast<size_t>(rand())%gameWindowWidth, static_cast<size_t>(rand())%gameWindowHeight);

            ///We play the sound that notifies the player that they have picked up missile ammunition.
            missilePickupSound.play();

            ///This checks if any missile has been fired from the rocket object before.
            ///If no missiles have been fired from the rocket object, then the statements inside this if statement
            ///are not accessed.
            if(firedMissileCount>0)
            {
                ///We decrease the missile count in order
                ///to add a missile to the rocket's ammunition.
                --firedMissileCount;

                ///This sets the last fired missile state to true, i.e. not fired.
                ///This essentially adds a missile to the rocket's ammunition.
                missilesFired[firedMissileCount]=true;
            }
        }

        ///This is the case where the pickup missile duration reaches its boundary points
        ///of whether the missile pickup object will show or not.
        else if(missilePickupDuration==0||missilePickupDuration==1500)
        {
            ///We set up the missile pickup object's duration to be in all the valid ranges of whether
            ///the missile pickup object will show or not.
            missilePickupDuration=static_cast<size_t>(rand())%3000;

            ///We change the position of the missile pickup sprite to another position.
            missilePickupSprite.setPosition(static_cast<size_t>(rand())%gameWindowWidth, static_cast<size_t>(rand())%gameWindowHeight);
        }

        ///This is the case where we control how long
        ///the missile pickup object will show or not.
        else
        {
            ///This checks whether the missile pickup duration is equal to either boundary point
            ///so as to not keep decreasing it.
            if(missilePickupDuration!=0&&missilePickupDuration!=1500)
            {
                --missilePickupDuration;
            }
        }
    }
}

///This function updates the attributes pertaining to the rocket's, i.e. player's, health.
void updateHealth(const sf::Sprite& rocketSprite, const std::vector<bool>& obstaclesDestroyed, const std::vector<sf::Sprite>& obstacleSprites, size_t& currentHealth, sf::Text& healthText, bool gamePaused)
{
    ///This checks if the game is not paused.
    ///If the game is paused, then there is no need to update the health.
    if(!gamePaused)
    {
        ///Now we sequentially access all the obstacle objects to see if they collide with the rocket.
        ///If any obstacle object collides with the rocket, then the rocket, i.e. the player, loses health.
        for(size_t obstacleIndex=0; obstacleIndex<obstacleSprites.size(); ++obstacleIndex)
        {
            ///This if statement checks whether the obstacle was not destroyed, and
            ///the rocket, i.e. player, still has health, and if the rocket collides with an obstacle object.
            ///If the obstacle was destroyed and the rocket does not collide with any obstacle object, then
            ///we do not lose health; we lose health otherwise.
            if(currentHealth&&!obstaclesDestroyed[obstacleIndex]&&rocketSprite.getGlobalBounds().intersects(obstacleSprites[obstacleIndex].getGlobalBounds()))
            {
                ///We decrease the current health, programmatically signifying
                ///the rocket, i.e. player, is losing health.
                --currentHealth;

                ///We prepare an output string stream that will
                ///help in updating the player's current health.
                std::ostringstream currentHealthStringStream;
                currentHealthStringStream<<"HP: "<<currentHealth;

                ///We now update the text that will show the rocket's, i.e. player's, current health.
                healthText.setString(currentHealthStringStream.str());
            }
        }
    }
}

///This function updates the attributes pertaining to the player's score.
void updateScore(size_t firedMissileCount, const std::vector<bool>& missilesFired, const std::vector<sf::Sprite>& missileSprites, const std::vector<bool>& obstaclesDestroyed, const std::vector<sf::Sprite>& obstacleSprites, size_t& currentScore, sf::Text& scoreText, size_t gameWindowWidth, bool gamePaused)
{
    ///This checks if the game is not paused.
    ///If the game is paused, then there is no need to update the score.
    if(!gamePaused)
    {
        ///We now sequentially access all the missiles that have been fired from the rocket
        ///to see if they collide with any obstacle.
        ///If any missile collides with any obstacle, then we update the player's score appropriately.
        for(size_t missileIndex=0; missileIndex<firedMissileCount; ++missileIndex)
        {
            ///We now sequentially access the obstacles to see if any have collided with the
            ///missiles that have been fired from the rocket.
            for(size_t obstacleIndex=0; obstacleIndex<obstacleSprites.size(); ++obstacleIndex)
            {
                ///This if statement checks if an obstacle has not been destroyed
                ///and if a fired missile collided with an obstacle.
                ///If the obstacle is not destroyed and has collided with a fired missile, then we update the player's score; we do not otherwise.
                if(!obstaclesDestroyed[obstacleIndex]&&missileSprites[missileIndex].getGlobalBounds().intersects(obstacleSprites[obstacleIndex].getGlobalBounds()))
                {
                    ///We update the current score, programmatically signifying
                    ///the player's score is increasing.
                    ++currentScore;

                    ///We prepare an output string stream that will
                    ///help in updating the player's current score.
                    std::ostringstream currentScoreStringStream;
                    currentScoreStringStream<<"Score: "<<currentScore;

                    ///We now update the text that will show the player's current score.
                    scoreText.setString(currentScoreStringStream.str());

                    ///We now update the position of the score display to stay within bounds on the game screen.
                    scoreText.setPosition(gameWindowWidth-scoreText.getGlobalBounds().width-10, 1);
                }
            }
        }
    }
}

///This function gives the illusion of adding more obstacles to the game screen
///when a certain number of obstacles remain on the game screen.
///Note: The amount of obstacles remaining on the game screen before adding more obstacles is 5,
///although one can pass their desired amount to this function if they wish.
void addObstacles(std::vector<bool>& obstaclesDestroyed, size_t obstaclesRemaining=5)
{
    ///We check if the number of obstacles not destroyed amounts to less than or equal to
    ///the number of obstacles that have to remain on the game screen before
    ///adding more obstacles.
    if(std::count(obstaclesDestroyed.begin(), obstaclesDestroyed.end(), false)<=static_cast<ptrdiff_t>(obstaclesRemaining))
    {
        ///If the count matches the amount of obstacles to remain, we
        ///add more obstacles to the game.
        std::fill(obstaclesDestroyed.begin(), obstaclesDestroyed.end(), false);
    }
}

///This function updates the rocket's actions based on receiving events.
void updateRocket(sf::Sprite& rocketSprite, const sf::Time& elapsedTime, size_t gameWindowWidth, size_t gameWindowHeight, bool gamePaused, const sf::Event& ingameEvent)
{
    ///This checks whether the game is paused or not.
    ///If the game is paused, then there is no need to update the rocket's actions.
    if(!gamePaused)
    {
        ///This switch statement checks for the type of event and handles it appropriately.
        switch(ingameEvent.type)
        {
            ///This is the case where the player presses a key on the keyboard perhaps.
            case sf::Event::KeyPressed:
            {
                ///This switch statement checks what type of key that the player presses and handles it appropriately.
                switch(ingameEvent.key.code)
                {
                    ///This is the case where the player presses the down key on the keyboard,
                    ///prompting the rocket object to move down.
                    case sf::Keyboard::Down:
                    {
                        rocketSprite.move(0, elapsedTime.asMilliseconds());

                        ///We break out of the case in the switch statement.
                        break;
                    }

                    ///This is the case where the player presses the left key on the keyboard,
                    ///prompting the rocket object to move left.
                    case sf::Keyboard::Left:
                    {
                        rocketSprite.move(-elapsedTime.asMilliseconds(), 0);

                        ///We break out of the case in the switch statement.
                        break;
                    }

                    ///This is the case where the player presses the right key on the keyboard,
                    ///prompting the rocket object to move right.
                    case sf::Keyboard::Right:
                    {
                        rocketSprite.move(elapsedTime.asMilliseconds(), 0);

                        ///We break out of the case in the switch statement.
                        break;
                    }

                    ///This is the case where the player presses the up key on the keyboard,
                    ///prompting the rocket object to move up.
                    case sf::Keyboard::Up:
                    {
                        rocketSprite.move(0, -elapsedTime.asMilliseconds());

                        ///We break out of the case in the switch statement.
                        break;
                    }

                    ///This is the default case for when the key pressed cannot be
                    ///resolved to a suitable action from the rocket.
                    default:
                    {
                        ///We break out of the case in the switch statement.
                        break;
                    }
                }

                ///We break out of the case in the switch statement.
                break;
            }

            ///This is the default case for when an appropriate case cannot be reached
            ///in order to elicit an appropriate action from the rocket.
            default:
            {
                ///We break out of the case in the switch statement.
                break;
            }
        }

        ///This if statement checks whether the rocket object is out of viewing range.
        if(rocketSprite.getPosition().x<=0||rocketSprite.getPosition().x>=gameWindowWidth-rocketSprite.getGlobalBounds().width||rocketSprite.getPosition().y<=0||rocketSprite.getPosition().y>=gameWindowHeight-rocketSprite.getGlobalBounds().height)
        {
            ///We reset the initial position of the sprite for the rocket object.
            rocketSprite.setPosition(gameWindowWidth/2, gameWindowHeight-2*rocketSprite.getGlobalBounds().height);
        }
    }
}

///This function updates the missile's actions based on receiving events.
void updateMissiles(const sf::Sprite& rocketSprite, size_t& firedMissileCount, std::vector<bool>& missilesFired, std::vector<sf::Sprite>& missileSprites, sf::Sound& missileSound, bool gamePaused, sf::Event& ingameEvent)
{
    ///This checks if the game is either paused or the maximum number of missiles
    ///have already been fired from the rocket.
    ///If either of the above conditions is true, then there is no need to update
    ///the missile's actions; we do so otherwise.
    if(!gamePaused&&firedMissileCount<missileSprites.size())
    {
        ///This switch statement checks for the type of event and handles it appropriately.
        switch(ingameEvent.type)
        {
            ///This is the case where the player presses a key on the keyboard perhaps.
            case sf::Event::KeyPressed:
            {
                ///This switch statement checks what type of key that the player presses and handles it appropriately.
                switch(ingameEvent.key.code)
                {
                    ///This is the case where the player presses the space button
                    ///on the keyboard, prompting the rocket to fire a missile.
                    case sf::Keyboard::Space:
                    {
                        ///We update the latest missile that has not been fired to have been fired.
                        missilesFired[firedMissileCount]=true;

                        ///We set the position of the latest fired missile to spawn from the rocket.
                        missileSprites[firedMissileCount].setPosition(rocketSprite.getPosition().x+11, rocketSprite.getPosition().y);

                        ///We increase the fired missile count, signifying that another missile
                        ///has been fired from the rocket.
                        ++firedMissileCount;

                        ///We play the sound associated with firing a missile.
                        ///This is to notify the player when they have fired a missile from the rocket.
                        missileSound.play();

                        ///We break out of the case in the switch statement.
                        break;
                    }

                    ///This is the default case for when the key pressed cannot be
                    ///resolved to a suitable action for the missiles.
                    default:
                    {
                        ///We break out of the case in the switch statement.
                        break;
                    }
                }

                ///We break out of the case in the switch statement.
                break;
            }

            ///This is the default case for when an appropriate case cannot be reached
            ///in order to elicit an appropriate action from the missiles.
            default:
            {
                ///We break out of the case in the switch statement.
                break;
            }
        }
    }
}

///This function sets up the attributes relating to the game over message that tells the player
///that the game is over as well as displaying their final score from their previous session.
void setGameOverMessage(size_t currentScore, sf::Text& postgameText, size_t gameWindowWidth, size_t gameWindowHeight)
{
    ///We prepare an output string stream that will
    ///help in displaying the player's final score.
    std::ostringstream currentScoreStringStream;
    currentScoreStringStream<<currentScore;

    ///We set the postgame text's message to display that the game is over, the player's final score, as well as instructions on what to do next.
    postgameText.setString("Game Over!\n\nYour final score is "+currentScoreStringStream.str()+".\n\nPress P to play again.\n\nPress B to return to main menu.\n\nPress Q to quit the game.");

    ///We set up the initial position of the text for the postgame's title and instructions.
    postgameText.setPosition(gameWindowWidth/12, gameWindowHeight/4);
}

///This function resets the attributes corresponding to ingame objects.
///This is in case the player would like to play the game again.
void resetGame(sf::Sprite& rocketSprite, size_t& firedMissileCount, std::vector<bool>& missilesFired, std::vector<bool>& obstaclesDestroyed, size_t& currentHealth, sf::Text& healthText, size_t& currentScore, sf::Text& scoreText, size_t gameWindowWidth, size_t gameWindowHeight)
{
    ///We reset the initial position of the sprite for the rocket object.
    rocketSprite.setPosition(gameWindowWidth/2, gameWindowHeight-2*rocketSprite.getGlobalBounds().height);

    ///We reset the fired missile count to zero, effectively
    ///making the rocket's ammunition full again.
    firedMissileCount=0;

    ///We reset all the values of the missiles fired vector to false,
    ///signifying that the rocket never fired a missile.
    std::fill(missilesFired.begin(), missilesFired.end(), false);

    ///We reset all the values of the obstacles destroyed vector to false,
    ///signifying that an obstacle was never destroyed.
    std::fill(obstaclesDestroyed.begin(), obstaclesDestroyed.end(), false);

    ///We set the player's health to the maximum
    ///so the player can play again.
    currentHealth=100;

    ///We prepare an output string stream that will
    ///help in resetting the player's current health.
    std::ostringstream currentHealthStringStream;
    currentHealthStringStream<<"HP: "<<currentHealth;

    ///We now reset the text that will show the rocket's, i.e. player's, current health.
    healthText.setString(currentHealthStringStream.str());

    ///We set the player's current score to 0
    ///so the player can start a new game on a clean slate.
    currentScore=0;

    ///We prepare an output string stream that will
    ///help in resetting the player's current score.
    std::ostringstream currentScoreStringStream;
    currentScoreStringStream<<"Score: "<<currentScore;

    ///We now reset the text that will show the player's current score.
    scoreText.setString(currentScoreStringStream.str());

    ///We reset the initial position of the text for the score display.
    scoreText.setPosition(gameWindowWidth-scoreText.getGlobalBounds().width-10, 1);
}

int main()
{
    ///These are the variables for the rocket.
    bool rocketDestroyed;
    sf::Sprite rocketSprite;
    sf::Texture rocketTexture;

    ///These are the variables for the missiles which will be fired from the rocket.
    size_t firedMissileCount;
    std::vector<bool> missilesFired;
    std::vector<sf::Sprite> missileSprites;
    std::vector<sf::Texture> missileTextures;

    ///These are the variables for the obstacles which the rocket will have to destroy for game points.
    std::vector<bool> obstaclesDestroyed;
    std::vector<sf::Sprite> obstacleSprites;
    std::vector<sf::Texture> obstacleTextures;

    ///These are the variables for setting and updating speeds and/or times of different components of the game.
    sf::Clock gameClock;
    sf::Time elapsedTime;

    ///These are the variables for health pickups for the game.
    size_t healthPickupDuration;
    sf::Sprite healthPickupSprite;
    sf::Texture healthPickupTexture;

    ///These are the variables for missile pickups for the game.
    size_t missilePickupDuration;
    sf::Sprite missilePickupSprite;
    sf::Texture missilePickupTexture;

    ///These are the variables for playing a sound to notify the player when they pickup health.
    sf::Sound healthPickupSound;
    sf::SoundBuffer healthPickupSoundBuffer;

    ///These are the variables for playing a sound to notify the player when they pickup missiles.
    sf::Sound missilePickupSound;
    sf::SoundBuffer missilePickupSoundBuffer;

    ///These are the variables for playing a sound when the player fires a missile from the rocket.
    sf::Sound missileSound;
    sf::SoundBuffer missileSoundBuffer;

    ///These are the variables for playing a sound if or when the player destroys an obstacle.
    sf::Sound obstacleSound;
    sf::SoundBuffer obstacleSoundBuffer;

    ///These are the variables for playing a sound if or when the rocket gets destroyed.
    sf::Sound rocketSound;
    sf::SoundBuffer rocketSoundBuffer;

    ///This is the variable for playing the music at the start menu of the game.
    sf::Music pregameMusic;

    ///This is the variable for playing the music during game play.
    sf::Music backgroundMusic;

    ///This is the variable for playing the music at the game over menu of the game.
    sf::Music postgameMusic;

    ///These are the variables for displaying the current health of the rocket on the game screen.
    size_t currentHealth;
    sf::Font healthFont;
    sf::Text healthText;

    ///These are the variables for displaying the current score the player has so far on the game screen.
    size_t currentScore;
    sf::Font scoreFont;
    sf::Text scoreText;

    ///These are the variables for showing the game's title and instructions before starting the game.
    sf::Font pregameFont;
    sf::Text pregameText;

    ///These are the variables for showing the paused text when pausing the game.
    sf::Font pausedgameFont;
    sf::Text pausedgameText;

    ///These are the variables for showing the game's game-over text and instructions after the game finishes.
    sf::Font postgameFont;
    sf::Text postgameText;

    ///These are the variables that set up the main window for the game.
    size_t gameWindowWidth;
    size_t gameWindowHeight;
    sf::RenderWindow gameWindow;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    ///These are the variables for controlling technical aspects of the game like pausing and when gameplay starts and stops.
    size_t gameStatus;
    bool gamePaused;

    ///We set up the seed for the random number generator for various aspects of the game.
    srand(time(NULL));

    ///We set up the rocket's variables.
    setRocket(rocketDestroyed, rocketSprite, rocketTexture, "rocket_sprite.png");

    ///We set up missiles' variables.
    setMissiles(firedMissileCount, missilesFired, missileSprites, missileTextures, "missile_sprite.png");

    ///We set up the obstacles' variables.
    setObstacles(obstaclesDestroyed, obstacleSprites, obstacleTextures, "obstacle_sprite.png");

    ///We set up the health pickup's variables.
    setHealthPickup(healthPickupDuration, healthPickupSprite, healthPickupTexture, "health_pickup.png");

    ///We set up the missile pickup's variables.
    setMissilePickup(missilePickupDuration, missilePickupSprite, missilePickupTexture, "missile_pickup.png");

    ///We set up the sound for the health pickup's variables.
    setHealthPickupSound(healthPickupSound, healthPickupSoundBuffer, "health_pickup_sound.wav");

    ///We set up the sound for the health pickup variables.
    setMissilePickupSound(missilePickupSound, missilePickupSoundBuffer, "missile_pickup_sound.wav");

    ///We set up the sound for the missiles' variables.
    setMissileSound(missileSound, missileSoundBuffer, "missile_sound.wav");

    ///We set up the sound for the obstacles' variables.
    setObstacleSound(obstacleSound, obstacleSoundBuffer, "obstacle_sound.wav");

    ///We set up the sound for the rocket's variables.
    setRocketSound(rocketSound, rocketSoundBuffer, "rocket_sound.wav");

    ///We set up the music that will play before gameplay starts.
    setPregameMusic(pregameMusic, "pregame_music.wav");

    ///We set up the music that will play during gameplay.
    setBackgroundMusic(backgroundMusic, "background_music.wav");

    ///We set up the music that will play after gameplay is over.
    setPostgameMusic(postgameMusic, "postgame_music.wav");

    ///We set up the health display's variables.
    setHealthDisplay(currentHealth, healthFont, healthText, "soft_marshmallow_font.otf");

    ///We set up the score display's variables.
    setScoreDisplay(currentScore, scoreFont, scoreText, "soft_marshmallow_font.otf");

    ///We set up the pregame text's variables.
    setPregameText(pregameFont, pregameText, "soft_marshmallow_font.otf");

    ///We set up the paused game text's variables.
    setPausedgameText(pausedgameFont, pausedgameText, "soft_marshmallow_font.otf");

    ///We set up the postgame text's variables.
    setPostgameText(postgameFont, postgameText, "soft_marshmallow_font.otf");

    ///We set up the game window's variables.
    setGameWindow(gameWindowWidth, gameWindowHeight, gameWindow, backgroundSprite, backgroundTexture, "background_texture.png");

    ///We set up the technical variables.
    setGameTechnicals(gameStatus, gamePaused);

    ///We set the initial positions of various game objects pertaining to the game screen.
    setInitialPositions(gameWindowWidth, gameWindowHeight, rocketSprite, healthPickupSprite, missilePickupSprite, healthText, scoreText, pregameText, pausedgameText);

    ///We start and enjoy the game!

    ///This while loop will stay true as long as the game window is open i.e. the player does not quit the game.
    while(gameWindow.isOpen())
    {
        ///We clear the game window to refresh it so updates to game objects can be shown.
        ///Note: The clear color is a purple-like color.
        gameWindow.clear(sf::Color(255, 0, 128));

        ///We continually draw the background sprite so the game's background can continually show.
        gameWindow.draw(backgroundSprite);

        ///This switch statement controls at which phase of the game the player is, i.e. pregame, ingame, or postgame.
        switch(gameStatus)
        {
            ///This is the case where the player is in the pregame.
            case 0:
            {
                ///These if-else statements will control the flow of the pregame music
                ///based on whether the game is theoretically paused or not.
                if(pregameMusic.getStatus()!=sf::SoundSource::Playing)
                {
                    if(!gamePaused)
                    {
                        pregameMusic.play();
                    }
                }

                else if(pregameMusic.getStatus()==sf::SoundSource::Playing)
                {
                    if(gamePaused)
                    {
                        pregameMusic.pause();
                    }
                }

                ///We now draw the pregame's title, i.e. the games title, and instructions continuously
                ///as long as the player is in the pregame.
                gameWindow.draw(pregameText);

                ///We set up an event object which the game window will poll
                ///corresponding to an action the user does that could or could not pertain to the pregame.
                sf::Event pregameEvent;

                ///This while loop will continue to run as long as events keep
                ///coming in for the game window to process during the pregame.
                while(gameWindow.pollEvent(pregameEvent))
                {
                    ///This switch statement controls how the events coming in
                    ///during the pregame are processed.
                    switch(pregameEvent.type)
                    {
                        ///This is the case where the player presses the close, X, button on the game window.
                        case sf::Event::Closed:
                        {
                            ///The game window is instructed to close.
                            gameWindow.close();

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the game window loses focus.
                        ///This typically happens when the player switches windows on the computer.
                        case sf::Event::LostFocus:
                        {
                            ///We set the trigger that causes the game to pause to true,
                            ///theoretically pausing the game.
                            gamePaused=true;

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the player presses a key on the keyboard.
                        case sf::Event::KeyPressed:
                        {
                            ///This switch statement controls how the keys that are pressed are processed
                            ///during the pregame.
                            switch(pregameEvent.key.code)
                            {
                                ///This is the case where the player presses the P button,
                                ///prompting the game to start.
                                case sf::Keyboard::P:
                                {
                                    ///We stop the pregame music in order to get ready to play the ingame music.
                                    pregameMusic.stop();

                                    ///We set the trigger that causes the game to pause to false,
                                    ///theoretically unpausing the game in order to get ready for the ingame.
                                    gamePaused=false;

                                    ///We change the game status to notify the program that we are in the ingame stage.
                                    gameStatus=1;

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the case where the player presses the Q button,
                                ///prompting the whole program to terminate.
                                case sf::Keyboard::Q:
                                {
                                    ///We close the game window before terminating the program.
                                    gameWindow.close();

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the default case for when a case in the switch statement
                                ///cannot be specifically processed.
                                default:
                                {
                                    ///We break out of the case in the switch statement.
                                    break;
                                }
                            }

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the game window gains focus.
                        ///This typically happens when the player switches to the game window on the computer.
                        case sf::Event::GainedFocus:
                        {
                            ///We set the trigger that causes the game to pause to false,
                            ///theoretically unpausing the game.
                            gamePaused=false;

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the default case for when a case in the switch statement
                        ///cannot be specifically processed.
                        default:
                        {
                            ///We break out of the case in the switch statement.
                            break;
                        }
                    }
                }

                ///We break out of the case in the switch statement.
                break;
            }

            ///This is the case where the player is actually playing the game.
            case 1:
            {
                ///These if-else statements will control the flow of the background music
                ///based on whether the game is paused or not.
                if(backgroundMusic.getStatus()!=sf::SoundSource::Playing)
                {
                    if(!gamePaused)
                    {
                        backgroundMusic.play();
                    }
                }

                else if(backgroundMusic.getStatus()==sf::SoundSource::Playing)
                {
                    if(gamePaused)
                    {
                        backgroundMusic.pause();
                    }
                }

                ///We now draw the rocket continuously as long as the player has enough health
                ///to continue playing the game.
                gameWindow.draw(rocketSprite);

                ///We now draw the health display continuously to display the rocket's
                ///health as long as the player has enough health to continue playing the game.
                gameWindow.draw(healthText);

                ///We now draw the score display continuously to display the player's
                ///score as long as the player has enough health to continue playing the game.
                gameWindow.draw(scoreText);

                ///We get the elapsed time so far in order to properly update the
                ///game objects that rely on time.
                ///We also restart the game clock to get ready for the next set of game object updates.
                elapsedTime=gameClock.restart();

                ///We update the variables pertaining to missiles being fired from the rocket.
                updateFiringMissiles(firedMissileCount, missileSprites, obstaclesDestroyed, obstacleSprites, elapsedTime, obstacleSound, gameWindow, gamePaused);

                ///We update the variables pertaining to the movement of the game obstacles.
                updateObstacles(rocketSprite, obstaclesDestroyed, obstacleSprites, elapsedTime, gameWindowWidth, gameWindowHeight, gameWindow, gamePaused);

                ///We update the variables pertaining to health pickup objects.
                updateHealthPickup(rocketSprite, healthPickupSprite, healthPickupSound, healthPickupDuration, currentHealth, healthText, gameWindowWidth, gameWindowHeight, gameWindow, gamePaused);

                ///We update the variables pertaining to missile pickup objects.
                updateMissilePickup(rocketSprite, firedMissileCount, missilesFired, missilePickupDuration, missilePickupSprite, missilePickupSound, gameWindowWidth, gameWindowHeight, gameWindow, gamePaused);

                ///We update the variables pertaining to the health display.
                updateHealth(rocketSprite, obstaclesDestroyed, obstacleSprites, currentHealth, healthText, gamePaused);

                ///We update the variables pertaining to the score display.
                updateScore(firedMissileCount, missilesFired, missileSprites, obstaclesDestroyed, obstacleSprites, currentScore, scoreText, gameWindowWidth, gamePaused);

                ///We check to see if more obstacles need to be added to the game.
                addObstacles(obstaclesDestroyed);

                ///We set up an event object which the game window will poll
                ///corresponding to an action the user does that could or could not pertain to the ingame.
                sf::Event ingameEvent;

                ///This while loop will continue to run as long as events keep
                ///coming in for the game window to process during the ingame.
                while(gameWindow.pollEvent(ingameEvent))
                {
                    ///This function updates the variables relating to movement of the rocket object.
                    updateRocket(rocketSprite, elapsedTime, gameWindowWidth, gameWindowHeight, gamePaused, ingameEvent);

                    ///This function updates the variables relating to the initial firing of missiles from the rocket object.
                    updateMissiles(rocketSprite, firedMissileCount, missilesFired, missileSprites, missileSound, gamePaused, ingameEvent);

                    ///This switch statement controls how the events coming in
                    ///during the ingame are processed.
                    switch(ingameEvent.type)
                    {
                        ///This is the case where the player presses the close, X, button on the game window.
                        case sf::Event::Closed:
                        {
                            ///The game window is instructed to close.
                            gameWindow.close();

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the game window loses focus.
                        ///This typically happens when the player switches windows on the computer.
                        case sf::Event::LostFocus:
                        {
                            ///We set the trigger that causes the game to pause to true,
                            ///effectively pausing the game.
                            gamePaused=true;

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the player presses a key on the keyboard.
                        case sf::Event::KeyPressed:
                        {
                            ///This switch statement controls how the keys that are pressed are processed
                            ///during the ingame.
                            switch(ingameEvent.key.code)
                            {
                                ///This is the case where the player presses the B button,
                                ///prompting the game to return to the pregame screen.
                                case sf::Keyboard::B:
                                {
                                    ///We stop the ingame music in order to get ready to play the pregame music.
                                    backgroundMusic.stop();

                                    ///We reset ingame object attributes that will allow us to start the game again.
                                    resetGame(rocketSprite, firedMissileCount, missilesFired, obstaclesDestroyed, currentHealth, healthText, currentScore, scoreText, gameWindowWidth, gameWindowHeight);

                                    ///We set the trigger that causes the game to pause to false,
                                    ///theoretically unpausing the game in order to get ready for the pregame.
                                    gamePaused=false;

                                    ///We change the game status to notify the program that we are in the pregame stage.
                                    gameStatus=0;

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the case where the player presses the P button,
                                ///prompting the game to pause or play depending on the previous state of the game.
                                case sf::Keyboard::P:
                                {
                                    ///we toggle the trigger that causes the game to pause or not depending
                                    ///on the previous state of the game.
                                    gamePaused=!gamePaused;

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the case where the player presses the Q button,
                                ///prompting the whole program to terminate.
                                case sf::Keyboard::Q:
                                {
                                    ///We close the game window before terminating the program.
                                    gameWindow.close();

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the default case for when a case in the switch statement
                                ///cannot be specifically processed.
                                default:
                                {
                                    ///We break out of the case in the switch statement.
                                    break;
                                }
                            }

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the default case for when a case in the switch statement
                        ///cannot be specifically processed.
                        default:
                        {
                            ///We break out of the case in the switch statement.
                            break;
                        }
                    }
                }

                ///This checks the game is paused or not.
                ///If the game is paused, then we draw the text that notifies the player
                ///that the game is paused.
                if(gamePaused)
                {
                    gameWindow.draw(pausedgameText);
                }

                ///This checks if the rocket still has health.
                ///If the rocket runs out of health, then the game is over and we move on to the post game.
                else if(!currentHealth)
                {
                    ///We stop the background music, getting ready for the post game.
                    backgroundMusic.stop();

                    ///We play the sound that signifies that the rocket has been destroyed,
                    ///i.e. the player has run out of health.
                    rocketSound.play();

                    ///We set the trigger that causes the game to pause to false,
                    ///theoretically unpausing the game in order to get ready for the postgame.
                    gamePaused=false;

                    ///We set the game status to 2, signifying that we are in postgame mode.
                    gameStatus=2;
                }

                ///We break out of the case in the switch statement.
                break;
            }

            ///This is the case where the game is over
            ///and the player can decide to play the game again or quit.
            case 2:
            {
                ///These if-else statements will control the flow of the postgame music
                ///based on whether the game is theoretically paused or not.
                if(postgameMusic.getStatus()!=sf::SoundSource::Playing)
                {
                    if(!gamePaused)
                    {
                        postgameMusic.play();
                    }
                }

                else if(postgameMusic.getStatus()==sf::SoundSource::Playing)
                {
                    if(gamePaused)
                    {
                        postgameMusic.pause();
                    }
                }

                ///This checks to see if the rocket was just destroyed or not.
                ///If the rocket was just destroyed, then we have to set the game over message;
                ///we do not do so otherwise.
                if(!rocketDestroyed)
                {
                    ///We set the rocket destroyed variable to true to signify that
                    ///the rocket is destroyed only one.
                    rocketDestroyed=true;

                    ///We set the game over message to signal to the player that the game is over as
                    ///well as to show their final score.
                    setGameOverMessage(currentScore, postgameText, gameWindowWidth, gameWindowHeight);
                }

                ///We now draw the postgame's title, i.e. the game over title, and instructions continuously
                ///as long as the player is in the postgame.
                gameWindow.draw(postgameText);

                ///We set up an event object which the game window will poll
                ///corresponding to an action the user does that could or could not pertain to the postgame.
                sf::Event postgameEvent;

                ///This while loop will continue to run as long as events keep
                ///coming in for the game window to process during the postgame.
                while(gameWindow.pollEvent(postgameEvent))
                {
                    ///This switch statement controls how the events coming in
                    ///during the postgame are processed.
                    switch(postgameEvent.type)
                    {
                        ///This is the case where the player presses the close, X, button on the game window.
                        case sf::Event::Closed:
                        {
                            ///The game window is instructed to close.
                            gameWindow.close();

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the game window loses focus.
                        ///This typically happens when the player switches windows on the computer.
                        case sf::Event::LostFocus:
                        {
                            ///We set the trigger that causes the game to pause to true,
                            ///theoretically pausing the game.
                            gamePaused=true;

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the player presses a key on the keyboard.
                        case sf::Event::KeyPressed:
                        {
                            ///This switch statement controls how the keys that are pressed are processed
                            ///during the postgame.
                            switch(postgameEvent.key.code)
                            {
                                ///This is the case where the player presses the B button,
                                ///prompting the game to return to the pregame screen.
                                case sf::Keyboard::B:
                                {
                                    ///We stop the postgame music in order to get ready to play the pregame music.
                                    postgameMusic.stop();

                                    ///We reset ingame object attributes that will allow us to start the game again.
                                    resetGame(rocketSprite, firedMissileCount, missilesFired, obstaclesDestroyed, currentHealth, healthText, currentScore, scoreText, gameWindowWidth, gameWindowHeight);

                                    ///We set the trigger that causes the game to pause to false,
                                    ///theoretically unpausing the game in order to get ready for the pregame.
                                    gamePaused=false;

                                    ///We set the trigger that signifies whether the rocket is destroyed once to false
                                    ///in order to show an updated final score after repeated gameplay.
                                    rocketDestroyed=false;

                                    ///We change the game status to notify the program that we are in the pregame stage.
                                    gameStatus=0;

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the case where the player presses the P button,
                                ///prompting the game to start again.
                                case sf::Keyboard::P:
                                {
                                    ///We stop the postgame music in order to get ready to play the ingame music.
                                    postgameMusic.stop();

                                    ///We reset ingame object attributes that will allow us to start the game again.
                                    resetGame(rocketSprite, firedMissileCount, missilesFired, obstaclesDestroyed, currentHealth, healthText, currentScore, scoreText, gameWindowWidth, gameWindowHeight);

                                    ///We set the trigger that causes the game to pause to false,
                                    ///theoretically unpausing the game in order to get ready for the ingame.
                                    gamePaused=false;

                                    ///We set the trigger that signifies whether the rocket is destroyed once to false
                                    ///in order to show an updated final score after repeated gameplay.
                                    rocketDestroyed=false;

                                    ///We change the game status to notify the program that we are in the ingame stage.
                                    gameStatus=1;

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the case where the player presses the Q button,
                                ///prompting the whole program to terminate.
                                case sf::Keyboard::Q:
                                {
                                    ///We close the game window before terminating the program.
                                    gameWindow.close();

                                    ///We break out of the case in the switch statement.
                                    break;
                                }

                                ///This is the default case for when a case in the switch statement
                                ///cannot be specifically processed.
                                default:
                                {
                                    ///We break out of the case in the switch statement.
                                    break;
                                }
                            }

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the case where the game window gains focus.
                        ///This typically happens when the player switches to the game window on the computer.
                        case sf::Event::GainedFocus:
                        {
                            ///We set the trigger that causes the game to pause to false,
                            ///theoretically unpausing the game.
                            gamePaused=false;

                            ///We break out of the case in the switch statement.
                            break;
                        }

                        ///This is the default case for when a case in the switch statement
                        ///cannot be specifically processed.
                        default:
                        {
                            ///We break out of the case in the switch statement.
                            break;
                        }
                    }
                }

                ///We break out of the case in the switch statement.
                break;
            }

            ///This is the default case for when a case in the switch statement
            ///cannot be specifically processed.
            ///This will never be reached theoretically, it is there for completeness.
            default:
            {
                ///We break out of the case in the switch statement.
                break;
            }
        }

        ///We display all the updates in the game window.
        gameWindow.display();
    }

    return 0;
}
