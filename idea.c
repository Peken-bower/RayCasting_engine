/*
    so scale it's easy i can be 100 for each cub.
    but what if i can do something better so for 
    example i have see this post that talk about 
    speed and distance in pubg is not the same 
    concept but i get a idea from here (https://www.reddit.com/r/PUBATTLEGROUNDS/comments/82ln4o/if_you_do_the_math_the_pubg_character_has_a_3/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)

    so let's think about this map 

    111
    1P1 => at this cas the player should move or NO ? 
    111

    in my cas yes this player should move for example if cub hight = player hight * 2 
    so the logic of cub is (height = length = width) so when player have half of height
    so it's not logic to get the length of 1 cub at 1 step ??? 
    after searching i have find this 
    On average, adults have a step length of about 2.2 to 2.5 feet. In general, if you divide a person's step length by their height, the ratio value you get is about 0.4 (with a range from about 0.41 to 0.45).
    check this here (https://www.scientificamerican.com/article/bring-science-home-estimating-height-walk/#:~:text=On%20average%2C%20adults%20have%20a,from%20about%200.41%20to%200.45).)
    so i will take this each step is 0.5 of player height so 1 step to center and 2 step from start to end . 
    so let's say this if i can be logic if i check speed and distance if i have a big map for example 
    100 cub will be 200 step to get the end of map if the player work in the same dir without stop and move 
    and if i do calculation and i render so that it's take time so the worst 1s or more let's say 1s now ? 
    so 200s cause each time player move i will update and if it's stay in the same dir it's can be easy for calculation 
    3.5min to get the end is not bad  but i cas of 1000 cub it's can be very base . is too
    now let's check when i need change the logic if i take 1s for each move so when i get 10min to move from 
    start to the end i need to change logic so simple math say 600 step so if the map have 300 cub
    so this cas i think it's not need to be in this simple project so optimization i need to check it later 
    so now let's check what i have i have a cub the cub demontion is 2 * player height and player one step is the helf of player hight 

    so now let's talk about scale of cub in monitor let's back to first map
    111
    1P1 
    111

    => so here the FOV is 60° but the player how much can see of map 
    * fov it's will be on the same facing cub cause distance is 1 or 0,5 or 0 (start, middel , end)
    => so in cas of 2 cub distance so here we need some math (check geogebra)

*/


/*
    RayCasting Doc: 
        Raycasting is a rendering technique to create a 3D perspective in a 2D map
        
        so how it's work : {
            Ray casting work by emitting a ray from the observation point 
            to each pixel and finding the closest object 
            that blocks the light path in the world scene
            and give back info about this point of hit (wall x,y) ...
        }
        so what i need : 
        {
            => i need map, : map or world scene where i will applay raycasting.
            => i need init pos : first pos where i will start raycasting.
            => i need fov : how much eye can see .
            => i need camera plan : the surface of what i can see (display screen)
        }
        so what i have : 
        {
            => i have char **map is a square grid each square on this 2d can 
            be '0' or '1' so if it's '0' that means is empty if it's '1' so that is a wall
            => init pos will be the player pos i can get it from map and i can get direction side 
            => it's already defined as maroc FOV it's 60° 
            => the camera plan can be calculated using (player pos) (player dir) (fov) 
                so the camera plan can be get it using 2 approch (vectors) (angles)

            => so here i will thinking about plan and map so scale : 

        }

*/


/*think about it ??

    this is just some idea 
    It may or may not be achieved
    I don't want to lose them so I'll write them down


    1- processing map before start 
    this a optimal hack that can 
    give me the wall pos inside map
    so the operation will just give me 
    the wall pos on 2d plan so that can 
    help actuly it's help also the ray pos 
    will be helped so i have 9 posible 
    pos and 4 dir so this will be 36 cas and 
    can be less cuz some pos is duplicated 
    and can be more in cas if i use mose move 
    every side of this (NSWE) can be 
    {(NW)(NE)}{(SW)(SE)}(NN)(SS)(W)(E)
    so 6 dir with 9 pos will be 54 so think about it ????
    but you will do it just one time to get info about map 
    with this can save time and can make raycasting super fast 
    i have idea in my mind but i will take more memory 
    but it's ok we are in heap so i think about divide 
    map in to 4 section

    (0, y / 2)
        (0, x/2)
        (x/2 +1, x)
    (y / 2 +1 , y)
        (0, x/2)
        (x/2 +1, x)
    
    this map don't have any empty space i will save just x and y 
    of wall of the original map so what i can do .: ok let's back to this
    idea now after the 2 idea and 3 idea i think about hash map if ican 
    store the (x,y) in hash map it's good o(1) in normal cas and o(n) worst 
    cas so way not so now after updating idea 2 i start getting value for 
    2d map and store all the wall pos and i need just start pos of ray 
    and director of ray and i can know all the pos that will ray pass
    from it and also i will applay the scale of apparent size and also 
    i will check data of empty space area to avoid checking evey time 
    if the ray point start on a empty area i will directly start for 
    end of this empty area but i will keep the same vector dir or 
    Orientation coefficient so if is not a empty area it's a wall so
    i will get x and y of this wall. (oh fuck fuck way i need to store wall i will store just empty spaces)
    so let's code this and see if this will be good or no


    2- so also i have something it's call formula for calculating apparent size
    Reference: https://www.physicsforums.com/threads/how-to-calculate-apparent-size-of-an-object-based-on-distance.730615/
    this is good in cas i want to know apparent of square, cause the floor will be also a square so unit of measurement
    will be 2m * 2m for square and distance will be also 0,5m for each move 

    so  apparent size = square size / distance 


    also this need some improvment cause the player pos can be change and side also and view dir will diffrent so 
    i need to check that 

    (update)
    remeber that the case of 300 cub in floor on the same dir it's the must big case
    so test with it and also when the  
    apparent size must be > 0 so the min value must be (need to think about it)

    can i get min value using the repense of this question
        * : using you fov and you are 2m away from wall that have 2m 
        how much of cub you see ? 
        
        => so meby is just pythagoras theorem casue i know fov is 60° 
        i know vector that represent center of fov and i know distance 
        so i can applay the pythagors theorem so how much d° this wall represent 
        in my fov so i can get a scale to applay this and make it fast 

    3- using the 1 idea i can do something is create a base of values that can stor (x,y) of all the pos 
    of ray using player pos and dir . so i will do that for a squre unit and 
    take the intersection point also this intersection will use the apparent size 
    the most exacte value.

*/

