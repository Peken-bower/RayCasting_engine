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