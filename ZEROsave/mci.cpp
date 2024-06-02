#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include "mci.h"

UINT BgmId;
MCIDEVICEID EffectID;

void PlayBgm(LPCWSTR _soundName, int _volume) {
	// 다시 불러졌을 때 기존거 닫기 위함
	mciSendCommand(BgmId, MCI_CLOSE, NULL, (DWORD)NULL);

	MCI_OPEN_PARMS openBgm;
	openBgm.lpstrElementName = _soundName;
	// mp3 : mpegvideo, wav : waveaudio
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	BgmId = openBgm.wDeviceID;

	// 볼륨 로직
	std::wstring msg = L"setaudio " + std::wstring(_soundName) + L" volume to " + std::to_wstring(_volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);

	MCI_PLAY_PARMS playBgm;
	mciSendCommand(BgmId, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)&playBgm);
}
void PlayEffect(LPCWSTR _soundName) {
	MCI_OPEN_PARMS openEffect;
	openEffect.lpstrElementName = _soundName;
	openEffect.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
	EffectID = openEffect.wDeviceID;

	// Play
	MCI_PLAY_PARMS playEffect;
	mciSendCommand(EffectID, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
	mciSendCommand(EffectID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);

	// close
	mciSendCommand(EffectID, MCI_CLOSE, NULL, (DWORD)NULL);
}