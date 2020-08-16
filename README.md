# Watopoly

# Introduction

The Watopoly project focuses on the application of Object-Oriented Design principles along with the minimization of coupling and cohesion between classes. Our project applies design patterns such as the Subject/Observer pattern and components from the Strategy Design pattern to achieve these goals.
The following document highlights the strength of these design choices, along with the challenges during the implementation process. Moreover, this document will discuss the flexibility that accompanies the chosen design principles.

# Overview

The project can be divided into the following files:
1. main.cc
2. board.cc and board.h
3. tile.cc and tile.h
4. nonproperty.cc and nonproperty.h
5. academicbuilding.cc and academicbuilding.h
6. residence.cc and residence.h
7. gym.cc and gym.h
8. nonproperty.cc and nonproperty.h
9. slc.cc and slc.h
10. gototims.cc and gototims.h
11. goosenesting.cc and goosenesting.h
12. collectosap.cc and collectosap.h
13. needleshall.cc and needleshall.h
14. coopfee.cc and coopfee.h
15. tuition.cc and tuition.h
16. textdisplay.cc and textdisplay.h
17. subject.cc and subject.h
18. observer.cc and observer.h

The client code and menu interface has been implemented in main where the main interaction of the client and the game in through the board object.
The board object acts as the main interaction container between the client and the game itself. Our design focuses on the board being the main container to provide commands such as roll, next, trade and other command line arguments which change or affect the state of the game. The board container is designed to hold pointers, references or collections of various components of the game. It can also keep track of other components by attaching them as Observers, since the board class inherits from subject.cc.

We have divided the tiles into the given interface where the tile abstract base class is inherited by its subclasses academicbuilding.cc, residence.cc, gym.cc, nonproperty.cc and its subclasses: slc.cc, dctimline.cc, gototims.cc, goosenesting.h, collectosap.cc, needleshall.cc, coopfee.cc and tuition.cc. The tile class provides the pure virtual function landed that is implemented for each subclass. The landed functions handle the payment of rent, any bankruptcy issues or can move the player anywhere on the
board (for example the slc.cc tile), which is like the Strategy design pattern principle. Moreover, the tile class provides various ways for the board to access and mutate the given tiles.

The text display object displays the current state of the board. It is updated whenever a player moves on the board or when improvements are bought by a player on an Academic tile. The text display object inherits from the Observer class and can override the desired notify functions.
The subject and observer class files are there to implement the Subject/Observer design pattern and consist of some overridden methods in the derived classes for the respective base classes.

The following features have been implemented in the game:
1. Buying properties (along with auctioning details)
2. Loading a game
3. Testing mode
4. Saving a game
5. Rolling the dice and player movement on text display
6. Declaring bankruptcy
7. Trading
8. Tile specific behaviours (paying rent, SLC/NeedlesHall etc)
9. Buying/Selling improvements along with notifying the display about the change

Features such as buying properties, loading a game, testing mode, saving a game, rolling the dice and player movement on text display, declaring bankruptcy, trading and buying/selling improvements along with notifying the display about the change have dedicated implementations in the board class.
These implementations in the board class of buying and selling further rely on the buying and selling methods present in the individual tile types.
Moreover, features such as testing mode, saving and loading a game are implemented in board as well, since the board is always aware of the state of the game.
Tile specific behaviours, such as the procurement of rent on a property tile or the SLC/NeedlesHall tile behaviours, are implemented in the pure virtual landed function that is overridden in the different derived classes.

The following are the ways you can interact menu of the game, note: all commands are case sensitive:
1. roll: rolls the die, a player cannot roll the dice more than once in their turn
2. next: gives the control to the next player, hence ending the turn of the current player
3. trade <name> <give> <receive>: allows the current player to trade with <name> where, <give> is the item being offered by the current player in exchange for <receive>, which is the item they ask for from <name>. <give> and <receive> can be the combination of a <property> for a <property>, money for a <property> or <property> for some money
4. improve <property> buy: allows the current player to buy an improvement on the academic building called <property> that they own
5. improve <property> sell: allows the current player to buy an improvement on the academic building < property> that they own
6. mortgage <property>: allows the current player to mortgage the given <property> that they own
7. unmortgage <property>: allows a player to unmortgage the given <property> that they own
8. bankrupt: allows the current player to declare bankruptcy
9. assets: displays the current player's assets
10. all: print the assets of all players in the game
11. save <filename>: saves the game in the given filename
12. -load <filename>: load the given file and resumes the game.
13. -testing die1 die2: enables testing mode where die1 and die2 and two non-negative integers that simulate the roll of two die. If either one is not supplied, then a regular roll is executed.
14. quit: quits the game entirely
15. menu : prints the menu of commands
16. -seed: sets the seed using 246 or time(NULL), mainly for reproducibility purposes.
  
Note: Since the game relies on user input throughout the game, some prompts asking for user input appear during certain situations, but this is the main interaction defined in the client code.

# Design

A major challenge while implementing the game design is when it comes to updating the state of the board and the associated text display object. The choice of the Subject/Observer design pattern was to minimize the need to store multiple display objects in the board object and to minimize the process of writing multiple specific notifying functions.

By using this design pattern, we allow the board to be the Subject, since it is always aware of the current state of the game, and allow the text display object to be the Observer, that executes it’s appropriate notify function when a player moves on the board or when an improvement is added.
The advantage of applying this design pattern minimizes the coupling between the board and the various display objects that can be employed. By storing multiple attached observers in our Subject class, we can invoke the notification/update functions easily by iterating through the attached observers lists by using the notifyObservers function.

Another challenge was associated with the implementation of the specific behaviour of each tile on the board. To overcome this problem, we partially implemented the Strategy design pattern through our tile interface. The tile interface declares a function called landed which, implements the specific behaviour of each tile such as Academic Building, Residence, Gym and Non-Property buildings. Our classes Academic Building, Residence, Gym and Non-property inherit from the tile interface and override the given function in the classes or sub-classes in the case of Non-Property buildings.
The advantage of applying this design pattern allows each component of the board to execute its specific algorithm through one entry function, in our case landed. Thus, the tile interface can provide multiple algorithms through the landed interface, depending on the implementation of this method within the sub-classes.
The main differences between our original UML and the current UML is the inheritance of the Subject and Observer classes. We decided to keep the board as the Subject and the Text Display as the one observer instead. It made sense to make board the Subject since it contain all the other containers such as Player and the Tiles. Whenever and update occurs through the game, we can use the notifyObservers() function to call the appropriate notify function for our Observer (Text Display). It proved to be advantageous since the notifyObservers() function is called whenever a change occurs and updates are made accordingly on Text Display. Moreover, this reduced the potential extra dependency the Text Display object might have had with the Player class, reducing coupling.

# Resilience to Change

We believe the following reasons highlight the flexibility available in our code to accommodate for new changes:
1. The tile interface provides a pure virtual function called landed to all tiles that inherit from it. This function can be overridden by the derived class to provide their specific functionality. For example, we can add more non property tiles that could implement their own behaviours in the overridden landed function.

2. The board interacts with any tile type regardless of whether it is a non-property or property. Through polymorphism, we can execute the various tile functions overridden in respective classes, regardless of the type of the tile (whether it is property or non-property).

3. The client code can accommodate for new commands within the if structure, following the same logic and the implementation of the new command can be placed into the board interface.

4. A change in rules of a tile’s behaviour only requires a change in its respective .cc file within the landed function. An addition of new tiles/rules requires the create of a new .cc file where the landed function can provide the implementation of the desired rule.

5. The Subject/Observer design pattern allows the board to have other observers that it can update as the game progresses. The notify functions defined for each observer can be overridden to execute the appropriate update method for when a player moves or when an academic building has an improvement added to it.

6. The use of smart pointers reduces the need to explicitly define destructors for our classes. Instead we can define pure virtual destructors, and the smart pointers will call the appropriate destructor once the object goes out of scope.

7. Since this project relies heavily on searching through containers, the STL algorithm library used allows for flexible search between numerous containers. Furthermore, the STL containers used allow more dynamic updates to occur easily throughout our game and doesn’t require additional classes to be made to store collections.

8. House rules can be implemented in the specific tiles landed function and the board can provide the general interface for activating this option within our game. This technique can work for other house rules as well.

# Answers to Questions

# Question.
After reading this subsection, would the Observer Pattern be a good pattern to use when implementing a gameboard? Why or why not?
We believed the Subject/Observe design pattern would be suitable for implementing the gameboard and found it to be useful when updating the text display after every move.
A one to many relationship aids in updating numerous observers one subject could have by simply using the notifyObserserver() function define in the Subject class. This design pattern help keeps track of different containers by establishing the relationship of a Subject/Observer in our model.

# Question. 
Suppose that we wanted to model SLC and Needles Hall more closely to Chance and Com-
munity Chest cards. Is there a suitable design pattern you could use? How would you use it?
We believe that our current design which, follows the Strategy design for tile specific behaviour, models the SLC and Needles Hall tiles more closely to Chance and Community Chest cards. The reason is that the strategy design pattern allows for one entry point function where the function is overridden in the derived class. The overridden function can be tailored to execute the desired algorithm for the tile.
  
 # Question. 
 Is the Decorator Pattern a good pattern to use when implementing Improvements? Why or
why not?
  
Initially we believed that the Decorator Pattern would not be useful when incrementing the tuition owed with improvements on an academic building. However, upon further inspection, the Text Display object could have used the Decorator Pattern to add the Roman numerals on the tile for the display. The reason being that it alters the given display by adding to the original display, so its as if we are placing add-ons on the existing display.


# Final Questions

1. What lessons did this project teach you about developing software in teams? If you worked
alone, what lessons did you learn about writing large programs?
Software development in teams is difficult if the components being designed are heavily coupled and minimum modularization is present. If the classes are heavily coupled, then it is difficult for individual developers to compile and test their program since, they need to wait for the completion of other files first. This pushes back the testing phase tremendously which, is detrimental when developing a large project where multiple components interact and change the state of each other.
If the work was done by an individual, time would be the biggest factor affecting the development process because this project contains numerous components and features which need to implement to provide a playable game.
Moreover, the valuable input from team members on design aspects cannot be accounted for when working individually. Team members can provide their understanding of the requirements asked from by the developer and create and environment for more open discussions on what principles to employ.

2. What would you have done differently if you had the chance to start over?
A few things we would have done differently is the assignment and delegation of tasks. It would have been more fruitful to assign tasks to members based on their skillset and have certain files/tasks completed before the given dates in the DD1 table.
We believe these two factors would have significantly reduced the amount of time spent developing and would have increased the desired test coverage we wanted. The saved time could have been spent testing the deliverables component wise and having more integration
testing to account for different scenarios possible. The increased test coverage would have boosted the confidence we would have in the deliverable since, it would be a true indicator of how close our project is to the given requirements.

# Conclusion

By attempting this project, we have realized the significance of minimizing coupling and maximizing cohesion by making appropriate design choices for our model. Furthermore, we realized that these two factors play an important role in the software development cycle because they ensure deliverables can be isolated and tested before merging into the code base.
In conclusion, Object Oriented Design Principles allowed us to minimize coupling and maximize cohesion within our classes and model, thus reducing the amount of code and potential errors


