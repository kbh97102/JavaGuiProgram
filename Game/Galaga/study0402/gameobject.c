#include "gameobject.h"


void gameobject_init(void) {
	gameobject_imagecount = 0;
	image1 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\�׽�Ʈ��.bmp");
	image2 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\���Ͻ�����ȭ��.bmp");
	image3 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\user.bmp");
	image4 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\boss.bmp");
	image5 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\enemy.bmp");
	image6 = gameobject_imgload(L"C:\\Users\\����\\Desktop\\Study\\���͵�\\�̹���\\background.bmp");
	//����ξտ� L�����̱�
}


int gameobject_imgload(LPCWSTR path) { //LPCWSTR lp = ������ w = �����ڵ� str = ���ڿ� �̹��� �ҷ����� �Լ�
	image_object *target = (image_object*)malloc(sizeof(image_object));
	HBITMAP bitmap1; //��Ʈ�� �ڵ�
	HDC hdc1;
	BITMAP bit; // ���� ���� ������ �˱����� ���. bit.***�ϸ� ����

	bitmap1 = LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);//printf�������� , ��Ʈ�ʷε�
	hdc1 = CreateCompatibleDC(front_dc); // ĵ�������� front ����
	SelectObject(hdc1, bitmap1); // ��ȭ���� ������ ��ħ 
	GetObject(bitmap1, sizeof(BITMAP), &bit);//int c = ��Ʈ�� ������

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
		DeleteObject(imageArray[i]->bitmap); //ĵ���� �ѽð� ���� ���°� ���� �����߿�
		DeleteDC(imageArray[i]->img);
		free(imageArray[i]); //�����Ҵ��� �Ѹ�ŭ�� Ǯ��
		imageArray[i] = NULL; 
	}
}




