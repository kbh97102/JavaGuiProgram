#include "gameobject.h"


void gameobject_init(void) {
	gameobject_imagecount = 0;
	image1 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\테스트용.bmp");
	image2 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\겜일시정지화면.bmp");
	image3 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\user.bmp");
	image4 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\boss.bmp");
	image5 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\enemy.bmp");
	image6 = gameobject_imgload(L"C:\\Users\\보훈\\Desktop\\Study\\스터디\\이미지\\background.bmp");
	//모든경로앞에 L꼭붙이기
}


int gameobject_imgload(LPCWSTR path) { //LPCWSTR lp = 포인터 w = 유니코드 str = 문자열 이미지 불러오는 함수
	image_object *target = (image_object*)malloc(sizeof(image_object));
	HBITMAP bitmap1; //비트맵 핸들
	HDC hdc1;
	BITMAP bit; // 가로 세로 사이즈 알기위해 사용. bit.***하면 나옴

	bitmap1 = LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);//printf같은느낌 , 비트맵로딩
	hdc1 = CreateCompatibleDC(front_dc); // 캔버스만듬 front 복사
	SelectObject(hdc1, bitmap1); // 도화지와 종리를 합침 
	GetObject(bitmap1, sizeof(BITMAP), &bit);//int c = 비트맵 사이즈

	target->Xposition = 0;
	target->Yposition = 0;
	target->img = hdc1;
	target->bitmap = bitmap1;
	target->height = bit.bmHeight;
	target->width = bit.bmWidth;
	imageArray[gameobject_imagecount] = target;
	
	return gameobject_imagecount++;
}

void gameobject_destroy() {
	
	for (int i = 0; i < gameobject_imagecount; i++) { 
		DeleteObject(imageArray[i]->bitmap); //캔버스 뿌시고 종이 찢는게 좋음 순서중요
		DeleteDC(imageArray[i]->img);
		free(imageArray[i]); //동적할당을 한만큼만 풀기
		imageArray[i] = NULL; 
	}
}




