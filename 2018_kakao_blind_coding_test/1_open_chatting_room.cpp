/**
 *  [#1] 오픈채팅방
 *       - 명령어(유저 들어옴, 나감, 닉네임 변경)들의 기록이 주어졌을 때,
 *         최종적으로 변경된 닉네임들로 표시된 메세지 기록을 반환하기
 *       - Reference: https://programmers.co.kr/learn/courses/30/lessons/42888
 * 
 * 
 *  * Solution
 * 
 * 
 *  ** What I learned
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
        if (message[0] == 'E' || message[0] == 'C') {
            vector<string> words = parseMessage(message);
            id_nicknames[words[1]] = words[2];
        }
    }

    // 닉네임 바탕으로 메세지 변환하기
    vector<string> answer;
    for (string message : record) {
        if (message[0] == 'E') {
            vector<string> words = parseMessage(message);
            string finalMessage = id_nicknames[words[1]] + "님이 들어왔습니다.";
            answer.push_back(finalMessage);
        }
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