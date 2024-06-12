#include "TitleScene.h"

bool TitleScene::Init() 
{
    return true;
}

void TitleScene::Render()
{
    if (!isRendered) {
        wcout << R"(
          _____                     _____                     _____                    _______                                             
         /\    \                   /\    \                   /\    \                  /::\    \                                               
        /::\    \                 /::\    \                 /::\    \                /::::\    \                           
        \:::\    \               /::::\    \               /::::\    \              /::::::\    \                          
         \:::\    \             /::::::\    \             /::::::\    \            /::::::::\    \                       
          \:::\    \           /:::/\:::\    \           /:::/\:::\    \          /:::/~~\:::\    \                      
           \:::\    \         /:::/__\:::\    \         /:::/__\:::\    \        /:::/    \:::\    \                  
            \:::\    \       /::::\   \:::\    \       /::::\   \:::\    \      /:::/    / \:::\    \                
             \:::\    \     /::::::\   \:::\    \     /::::::\   \:::\    \    /:::/____/   \:::\____\          
              \:::\    \   /:::/\:::\   \:::\    \   /:::/\:::\   \:::\____\  |:::|    |     |:::|    |        
_______________\:::\____\ /:::/__\:::\   \:::\____\ /:::/  \:::\   \:::|    | |:::|____|     |:::|    |        
\::::::::::::::::::/    / \:::\   \:::\   \::/    / \::/   |::::\  /:::|____|  \:::\    \   /:::/    /        
 \::::::::::::::::/____/   \:::\   \:::\   \/____/   \/____|:::::\/:::/    /    \:::\    \ /:::/    /            
  \:::\----\                \:::\   \:::\    \             |:::::::::/    /      \:::\    /:::/    /               
   \:::\    \                \:::\   \:::\____\            |::|\::::/    /        \:::\__/:::/    /               
    \:::\    \                \:::\   \::/    /            |::| \::/____/          \::::::::/    /                   
     \:::\    \                \:::\   \/____/             |::|   |                 \::::::/    /                     
      \:::\    \                \:::\    \                 |::|   |                  \::::/    /             
       \:::\____\                \:::\____\                \::|   |                   \::/____/              
        \::/    /                 \::/    /                 \:|   |                                              
         \/____/                   \/____/                   \|___|                                                        
        )" << endl;
        isRendered = true;
    }
}