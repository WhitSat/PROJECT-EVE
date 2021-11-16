# PROJECT-EVE

# Stuff we want it to do 
* Read from other eavesdroppers 
* Read from master 
* Start a coup/reconfigure itself as master in case of master's death 
* Start a coup for the line of succession if needed in case of another eavesdropper's death

# Stuff we don't want it to do 
* Write to anybody/mess up data in the bus 

# Stuff to keep from master
* Ability to read data going out from at least one other eavesdropper  

# Stuff to keep from slave 
* Construction in slave mode
* Ability to read from master
* Individual addresses 

# Ideas for monitoring the master:
* General Call: master periodically calls all slaves, and eavesdroppers look for the message and acknowledge; if eavesdroppers don't receive message, execute succession.
* Multi-master: eavesdropper masters check on "mission" master and communicate with each other to resolve succession.
