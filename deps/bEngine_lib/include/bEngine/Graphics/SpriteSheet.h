///
/// \file SpriteSheet.h
/// \brief Load an compile a Spritesheet from an image file as a set of textures/sprites
/// \author benajah
/// \date 10/28/24
///

/*
 * Figure this shit out before you start to develop this becuase
 * you have not clue how you want to go about this yet
 */

#ifndef GAME_SPRITESHEET_H
#define GAME_SPRITESHEET_H

#include <vector>
namespace bEngine::GFX {

    typedef struct {
        int width, height;// might be used to pass information to a shader to resize the output
        GLuint base_spritesheet;
        VAO vao;
    } Sprite;

    typedef struct {
        std::vector<Sprite> sprites;
        int width, height;
        GLuint identifier;
    } SpriteSheet;

    SpriteSheet load_sprite_sheet( const std::filesystem::path &sprite_sheet_path );
}// namespace bEngine::GFX

#endif//GAME_SPRITESHEET_H
