// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02
// 프로젝트
// 3번 알고리즘
// 2018112025 박익범
// -----------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;
//입력 받은 파일의 총 지하철 개수
#define stationCount "100"
#define MAX 100

clock_t start, end_time = clock();

//모든 지하철 역 위치 입력받기
map<string, vector<string> > fileInput(string path) {
    map <string, vector <string> > locationData;
    ifstream readFile (path);
    string stationName;
    string lat;
    string lon;

    if (readFile.is_open()) {
        for(int i = 0; i < 640; i ++) {
            readFile >> stationName;
            readFile >> lat;
            readFile >> lon;
            //역 이름, 위도, 경도 를 각각 버퍼에서 불러내서 locationData로 선언해놓은 변수에 map형태로 삽입
            locationData[stationName + "역"] = vector<string> {lat, lon};
        }
    }
    //파일에서 불러온 전체 역 데이터 반환
    return locationData;
}

//inputfile을 불러오는 함수
vector <string> userfileInput(string path) {
    vector <string> userData;
    ifstream readFile (path);
    string stationName;

    if (readFile.is_open()) {
        for(int i = 0; i < stoi(stationCount) + 1; i ++) {
            readFile >> stationName;
            //파일갯수는 포함되지 않게 예외처리
            if (stationName != stationCount) {
                //불러온 파일을 userData벡터에 삽입
                userData.push_back(stationName);
            }
        }
    }
    //파일에서 불러온 전체 유저 역 데이터 반환
    return userData;
}

//난수값 생성함수
//알고리즘 사용할때, 첫 비교값을 랜덤으로 주기 위해서 사용함.
int makeRand() {
    srand((unsigned int)time(NULL));
    int randnum = rand();
    randnum = randnum % 9;
    return randnum;
}

//검색이 완료된 후 나온 역을 출력하는 함수
void printStation(double lat, double lon, map<string, vector<string> > sData) {
    double minLati = -1;
    double minLong = -1;
    //이터레이터를 이용해서 map의 value값을 이동시키며 범위내의 역들을 모두 검색
    for (auto iter = sData.begin(); iter != sData.end(); ++iter){
        double latNum = stod(iter -> second[0]);
        double lonNum = stod(iter -> second[1]);
        //검색결과로 나온 위도 경도를 역의 위도경도와 비교함
        //0.01 == 1km 임으로, 검색 결과된 좌표와 위도경도가 1km이내에 있는 모든 역들을 출력함.
        if (latNum + 0.01 >= lat && latNum - 0.01 <= lat){
            if(lonNum + 0.01 >= lon && lonNum - 0.01 <= lon){
                string data = iter -> first;
                cout << "[input " << MAX << "]" << endl;
                cout << "세 번째 알고리즘을 사용해 구한 중간 지점 역은 " << data << "입니다." << endl;
            }
        }
        }
    end_time = clock();
}


//분포 알고리즘 구현 부분
void distributionSolution(map<string, vector<string>> sData, vector<string> uData, int k) {
    vector<pair<double, double>> means;
    int group[MAX];

    //군집의 초기값 설정
    for(int i = 0; i < k; i ++) {
        //0 혹은 1번 인덱스로 처리
        int ran = makeRand();
        //sData는 역 이름에 따른 위도경도를 갖고있기 때문에, userData의 인덱스에 0~9의 랜덤값을 입력해서 역이름을 뽑아냄
        //뽑아낸 이름을 바탕으로 첫 means를 만들어둠
        means.push_back(make_pair(stod(sData[uData[ran]][0]), stod(sData[uData[ran]][1])));
    }

    while (true) {
        //검색이 완료된 경우 while문을 벗어나야 하니까 flag 선언
        bool flag = false;
        //처음에, 위치를 지정해준 group배열에 주변최소거리의 오브젝트들을 다 넣어주는 과정 (지금은 K=1이니까 모든 오브젝트가 다 들어갈 예정)
        for (int i = 0; i < uData.size(); i++) {
            //최소 거리와 최소값을 판단할 변수들 초기화
            double mDistance = MAX;
            int min = -1;

            //k == 내가 만들 분포의 중심의 갯수
            for(int j = 0; j < k; j++) {
                double distance = 0;
                //(x2-x1)^2 + (y2-y1)^2 두점사이의 거리공식을 이용해서 distance를 구함
                //동일한 조건이면 루트처리가 굳이 필요없을 것 같아 하지 않았음.
                distance = pow(means[j].first - stod(sData[uData[i]][0]),2) +  pow(means[j].second - stod(sData[uData[i]][1]),2);
                //최소거리보다 방금 구한 거리가 짧다면, 최소 거리를 교체 해주고, min값에 현재 j(인덱스)를 넣어줌.
                if(distance < mDistance) {
                    mDistance = distance; //거리
                    min = j; //방금 구한 제일 가까운 index값으로 바꾸어줌
                }
            }
            //그 후, 나눠놓은 Kgroup 배열에 min값을 넣어줌
            group[i] = min;
        }

        //k = 1개, 원래대로면 k의 갯수만큼 배열을 만들어서 안의 값을 바꾸어줘야되지만 지금은 분포의 평균을 하나로 구할꺼라 상관없음
        //구한 그룹들의 평균을 찾기위해서 각각의 위도경도값을 모두 더해줌.
        pair<double, double> temp[1];
        int count[1] = {};
        //유저 데이터의 갯수만큼 반복하며,
        //그 데이터의 위도경도들을 모두 더해줌
        for(int i = 0; i < uData.size(); i++) {
            count[group[i]]++;
            temp[group[i]].first += stod(sData[uData[i]][0]);
            temp[group[i]].second += stod(sData[uData[i]][1]);
        }
        //모두 더한 위도경도들의 값을 count(총 유저의 i 값)으로 나누어줌
        for(int i = 0; i < k; i++) {
            temp[i].first /= count[i];
            temp[i].second /= count[i];
            //우리의 k는 1이기 때문에, 모든 유저의 위도경도 값을 더해서 이를 총 유저수로 나눈것이 평균이 됨.
            //하지만, means는 맨처음 랜덤 인덱스 값을 이용해서 구현해놨기 때문에 이 값이 아님.
            //그래서 평균값의 오차범위를 판단하기 위해서 새로운 평균과 기존 평균의 값을 비교해줌
            //만약 이전 평균과 지금 평균의 차가 오차범위 (10m)를 벗어난다면, 평균값(mean)의 값을 바꾸고, 한번 더 연산을 실행함
            if (fabs(temp[i].first - means[i].first) > 0.0001 && fabs(temp[i].second - means[i].second) > 0.0001) {
                flag = true;
                means[i].first = temp[i].first;
                means[i].second = temp[i].second;
            }
        }
        //오차범위 안으로 수령했으면 주변의 역들을 출력해줌
        if (flag == false) {
            printStation(means[0].first, means[0].second, sData);
            break;
        }
    }
}


int main() {
    //파일 불러오기
    auto stationData = fileInput("//Users/parkikbum/Desktop/computerAlgorithm/cumputerAlgol/cumputerAlgol/station_location.txt");
    auto peopleData = userfileInput("/Users/parkikbum/Desktop/computerAlgorithm/cumputerAlgol/cumputerAlgol/input100.txt");

    //알고리즘 실행
    start = clock();
    distributionSolution(stationData, peopleData, 1);
    cout << "수행시간 : " << double(end_time - start) << endl;
}