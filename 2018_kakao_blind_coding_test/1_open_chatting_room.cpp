/**
 *  [1] 오픈채팅방
 *      : 채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 주어질 때, 
 *        최종적으로 변경된 닉네임이 반영된 채팅방의 들어옴/나감 기록을 반환하기
 *      - Reference: https://programmers.co.kr/learn/courses/30/lessons/42888
 * 
 * 
 *  [해결 방법]
 * 
 *    (1) 해시 테이블 사용: O(n) time, O(n) extra space
 *        -> unordered_map을 이용하여 각 아이디마다 닉네임 저장 및 변경
 *        -> 최종적으로 변경된 각 아이디의 닉네임을 들어감, 나감 메세지에 맞게 변환하여 반환
 * 
 * 
 *  [What I learned]
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<string> solution(vector<string> record) {

    // 각 아이디의 최종 닉네임을 저장
    unordered_map<string, string> id_nicknames;
    for (string message : record) {
        // 들어옴 또는 닉네임 변경 메세지에서 아이디와 닉네임 저장
        if (message[0] == 'E' || message[0] == 'C') {
            vector<string> words = parseMessage(message);
            id_nicknames[words[1]] = words[2];
        }
    }

    // 닉네임 바탕으로 메세지 변환하기
    vector<string> answer;
    for (string message : record) {
        // 들어옴 메세지에 최종 닉네임 대입하여 저장
        if (message[0] == 'E') {
            vector<string> words = parseMessage(message);
            string finalMessage = id_nicknames[words[1]] + "님이 들어왔습니다.";
            answer.push_back(finalMessage);
        }
        // 나감 메세지에 최종 닉네임 대입하여 저장
        if (message[0] == 'L') {
            vector<string> words = parseMessage(message);
            string finalMessage = id_nicknames[words[1]] + "님이 나갔습니다.";
            answer.push_back(finalMessage);
        }
    }
    return answer;
}

/**
 *  도움 함수: 주어진 문자열을 단어 단위로 파싱하여 반환
 */
vector<string> parseMessage(string s) {
    vector<string> words;
    
    string word = "";
    for (int i = 0, n = s.length(); i <= n; i++) {
        if (i == n || s[i] == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += s[i];
        }
    }

    return words;
}