Chuyun’s Rocket Game Project README
About
	This project was a project that one of my good friends from Georgetown University, Chuyun Liu, had in his first Computer Science class. He showed me the SFML (Simple and Fast Multimedia Library) third party API which he used to make the game. I decided, as a way to learn how to use SFML and build upon his project, to recreate it with additional parts. In terms of implementation, I decided to design the project using the procedural programming paradigm as it would allow me to use only the main thread in order to avoid data races. The Professor who assigned Chuyun this project was Jami Montgomery, a professor in the Computer Science department at Georgetown University.
Game Details
	The game is a 2D game. It consists of the player controlling a rocket and shooting obstacles that come your way to earn points. The player also has to watch out for their health because if their health runs out then the game is over. In addition, the player has to be careful of how many missiles they fire as the amount of missiles that the rocket carries is finite. In order to replenish health and missile ammunition watch for the health and missile pickups that pop up on the game screen. To pickup health or missile ammunition, simply have the rocket come in contact with a health or missile pickup.
	When the player first opens up the game, they will be greeted by the title screen with instructions how to proceed to playing or quitting the game. When playing the game and the player runs out of health, they will be greeted by the game over screen displaying their final score as well as instructions on how to proceed to play again or quit the game.
Game Controls
	I will list the controls, for convenience, for the title screen, when playing the game, and the game over screen.
Title Screen:
	X Button on window – closes the window, essentially quitting the game
	P button on keyboard – proceeds to gameplay
	Q button on keyboard – closes the window, thereby quitting the game
Game Screen
	P button on keyboard – pause/resume the game
	Q button on keyboard – closes the window, essentially quitting the game
	B button on keyboard – takes the player back to the title screen
	Left Arrow Key on keyboard – moves the rocket left
	Right Arrow Key on keyboard – moves the rocket right
	Up Arrow Key on keyboard – moves the rocket up
	Down Arrow Key on keyboard – moves the rocket down
	Space bar on keyboard – prompts rocket to shoot a missile
Game Over Screen
	X Button on window – closes the window, essentially quitting the game
	P button on keyboard – proceeds to gameplay
	Q button on keyboard – closes the window, thereby quitting the game
	B button on keyboard – takes the player back to the title screen
In addition to these controls, the game pauses when the player switches focus and if the player is currently playing the game, the player has to unpause the game to resume playing when the game screen regains focus. To unpause the game simply press the P button the keyboard. If the player was either on the title or game over screen, game processes will automatically resume when the game screen resumes focus. These things were done for the convenience for the player.
Executable File Use
	I have put the executable and all the other necessary files into a zip file for convenience. To run the game, simply open the executable file. Since the game is dynamically linked, all the dll and other files that comes with the executable are needed in order for the game to run. Before running the game, you must extract the folder located in the zip file, otherwise the game will not run. If one accidently deletes or misplaces any of those files, then they could simply download the zip file from my GitHub page again.
Copyright Notices
	I just want to make clear that I do not own the SFML third party API as well as any of the media files associated with this project. If anyone knows who the original author(s) of any of the media file sources, then please let me know so I can give credit where credit is due.
Helpful Links
	Here are some links that I have found to be really useful when doing the project. They cover many things from installing SFML to how to use the API properly.
•	https://www.sfml-dev.org/index.php
•	http://www.edparrish.net/common/sfmlcb.html

Source Code Use
	The source code associated with this project is free for anyone to use. If one has found any bugs or has any suggestions/questions relating to the source code, please comment on the project page or email me at rachidtelfort@gmail.com.
Final Notes
	I hope that my fellow coders will find the source code helpful as well as gain valuable insight from it. I certainly learned much from it and hope to use SFML in the future if I have time. I want to thank my good friend Chuyun for relaying the idea of the rocket game and SFML in the first place. To see some of his projects, his GitHub page is https://github.com/ChuyunLiu. I also would like to thank the SFML creators for creating a cool multimedia library. If you have read this, thank you for looking at my GitHub page it is much appreciated.

