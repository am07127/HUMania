#include<iostream>
#include "HUMania.hpp"
#include <vector>
using namespace std;


// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images





vector<Unit> pigeons;
//create 2 more vectors for bees and butterflies
vector<Unit> bees;
vector<Unit> butterflies;
int state1=0;


void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets)
{

    for (int i = 0; i < pigeons.size(); i++)
    {
        if (pigeons[i].srcRect.x == 7 && pigeons[i].srcRect.y == 88 && pigeons[i].srcRect.w == 155 && pigeons[i].srcRect.h == 103)
        {
            //pigeons[i].srcRect=={7,88,155,103}
            pigeons[i].srcRect={0,237,153,84};
            SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
            
            //state1++;
        }
        else if (pigeons[i].srcRect.x == 0 && pigeons[i].srcRect.y == 237 && pigeons[i].srcRect.w == 153 && pigeons[i].srcRect.h == 84)
        {
            //pigeons[i].srcRect={0,237,153,84};
            pigeons[i].srcRect={2,361,159,124};
            SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
            //state1++;
        }
            
        
        else if(pigeons[i].srcRect.x == 2 && pigeons[i].srcRect.y == 361 && pigeons[i].srcRect.w == 159 && pigeons[i].srcRect.h == 124)
        {
            //pigeons[i].srcRect={2,361,159,124};
            pigeons[i].srcRect={7,88,155,103};
            SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
            //state1=0;    
        }
        
        //SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
        pigeons[i].moverRect.x += 5;
        if(pigeons[i].moverRect.x>=1000){
            pigeons[i].moverRect.x=0;
        }
    }
    for (int i = 0; i < bees.size(); i++)
    {
        if (bees[i].srcRect.x == 527 && bees[i].srcRect.y == 138 && bees[i].srcRect.w == 194 && bees[i].srcRect.h == 231){
            bees[i].srcRect={540,370,193,115};
            SDL_RenderCopy(gRenderer, assets, &bees[i].srcRect, &bees[i].moverRect);
            
        }
        
        else if(bees[i].srcRect.x == 540 && bees[i].srcRect.y == 370 && bees[i].srcRect.w == 193 && bees[i].srcRect.h == 115)
        {
            //pigeons[i].srcRect={2,361,159,124};
            bees[i].srcRect={527,138,194,231};
            SDL_RenderCopy(gRenderer, assets, &bees[i].srcRect, &bees[i].moverRect);
            //state1=0;    
        }
        
        //SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
        bees[i].moverRect.x += 5;
        if(bees[i].moverRect.x>=1000){
            bees[i].moverRect.x=0;
        }
        
        
        
    }

    for (int i = 0; i < butterflies.size(); i++)
    {
        if (butterflies[i].srcRect.x == 257 && butterflies[i].srcRect.y == 24 && butterflies[i].srcRect.w == 173 && butterflies[i].srcRect.h == 134){
            //pigeons[i].srcRect=={7,88,155,103}
            butterflies[i].srcRect={257,182,192,214};
            SDL_RenderCopy(gRenderer, assets, &butterflies[i].srcRect, &butterflies[i].moverRect);
            
            //state1++;
        }
        else if (butterflies[i].srcRect.x == 257 && butterflies[i].srcRect.y == 182 && butterflies[i].srcRect.w == 192 && butterflies[i].srcRect.h == 214)
        {
            //pigeons[i].srcRect={0,237,153,84};
            butterflies[i].srcRect={248,432,248,179};
            SDL_RenderCopy(gRenderer, assets, &butterflies[i].srcRect, &butterflies[i].moverRect);
            //state1++;
        }
            
        
        else if(butterflies[i].srcRect.x == 248 && butterflies[i].srcRect.y == 432 && butterflies[i].srcRect.w == 248 && butterflies[i].srcRect.h == 179)
        {
            //pigeons[i].srcRect={2,361,159,124};
            butterflies[i].srcRect={257,24,173,134};
            SDL_RenderCopy(gRenderer, assets, &butterflies[i].srcRect, &butterflies[i].moverRect);
            //state1=0;    
        }
        
        //SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
        butterflies[i].moverRect.x += 5;
        if(butterflies[i].moverRect.x>=1000){
            butterflies[i].moverRect.x=0;
        }
        
        
        
    }
    

    

    // this functios is drawing one pigeon only right now
    //SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);
    //SDL_RenderCopy(gRenderer, assets, &bees.srcRect, &bees.moverRect);
    //SDL_RenderCopy(gRenderer, assets, &butterflies.srcRect, &butterflies.moverRect);

    // TODO: Write code to iterate over all the vectors and draw objects here: 
     //random variable
    
    
     // moves the pigeon two pixel towards right    pigeon.moverRect=x+2   modified from 2 to 1
    // changing the srcRect to other positions of pigeon will make the fly animation
    // SDL_RenderPresent is already called in game.cpp file, you don't need to call here
    
    
}


void createObject(int x, int y){

    // TODO: create an object randomly, and push it into corresponding vector
    int var1= (rand()%3);
    //int var1= 0;
    int i;
    if( var1==0 ){
        Unit pigeon = {{7,88,155,103}, {x, y, 50, 50}};
        pigeons.push_back(pigeon);
    }
    if (var1 == 1){
        Unit bee = {{527,138,194,231}, {x, y, 50, 50}};
        bees.push_back(bee);
    }
    if (var1==2){
        Unit bf = {{257,24, 173, 134}, {x, y, 50, 50}};
        butterflies.push_back(bf);
    }
    

    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

