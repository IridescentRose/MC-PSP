#pragma once
#include <string>
#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/Texture.h>
namespace Aurealis
{
	namespace Graphics
	{

		class Sprite
		{
		public:
			Sprite();
			Sprite(const char* filename);
			Sprite(const char* filename,int startW,int startH,int endW,int endH);
			Sprite(Texture* texture);
			Sprite(Texture* texture, int startW, int startH, int endW, int endH);
			Sprite(Texture* texture, int startW, int startH, int endW, int endH, bool obr);
			~Sprite();


            void SetMapPos(Texture* texture,int startW,int startH,int endW,int endH);
			void SetPosition(float x,float y);
			void Scale(float x,float y);
			void NewScale(float x);
			void RemoveImage();
			void Draw();
			void DrawNoModSet();
			void DrawLinear();

			void Alpha(float _alpha);
			void RGB(float _red, float _green, float _blue);

			float GetPositionX();
			float GetPositionY();


			Texture* tex;
			TexturedVertex *vertices;

			float scaleX,scaleY;
			float posX,posY;
			int width,height;
			int red, green, blue, alpha;
		};

	}

}