/**
 *  [문제] 완주하지 못한 선수
 *  : 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
 *    완주하지 못한 선수의 이름을 찾기
 *    (Reference: https://programmers.co.kr/learn/courses/30/lessons/42576)
 * 
 * 
 *  [해결 방법]
 * 
 *    (1) 해시 테이블 사용: O(n) time, O(n) extra space
 *        -> 선수 모두 해시 테이블에 저장 후, 완주 선수 제외시키기
 *        -> 해시 테이블에 남은 단 한 명의 선수 반환
 *        
 *        (1-1) unordered_map 사용: (선수이름, 몇 명인지) 저장
 *        (1-2) unordered_multiset 사용: 중복저장 가능
 *              -> 단, 삭제 시에는 find로 이터레이터를 찾은 후, 이터레이터로 삭제해야 함!
 * 
 *    (2) 정렬 후 비교: O(n logn) time, O(1) extra space
 *        -> 오름차순으로 participant과 completion 배열 정렬
 *        -> 순서대로 participant[i] == completion[i] 비교
 *           -> 같지 않을 경우, 해당 participant가 완주하지 못한 선수이다
 *        -> 모두 같을 경우,
 *           -> 지지막 남은 participant가 완주하지 못한 선수이다
 * 
 * 
 *  [What I learned]
 * 
 *     ** unordered_multiset 사용하는 방법
 *        - 라이브러리: #include <unordered_set>
 *        - 선언: unordered_multiset<자료구조> 이름
 *        - 한 키의 모든 중복된 값을 삭제하지 않고 하나만 삭제하기 위해서는
 *          반드시 이터레이터를 통해 삭제해야만 한다
 *          -> auto it = s.find(key)
 *          -> s.erase(it)
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1-1) unordered_map 사용
 */
string solution(vector<string> participant, vector<string> completion) {
    // 마라톤 경기에 참여한 선수 모두 해시에 저장
    unordered_map<string, int> list;
    for (string person : participant) {
        if (list.count(person) > 0) {
            list[person]++;
        } else {
            list[person] = 1;
        }
    }
    // 완주한 선수들을 대상으로 해시에서 제외
    for (string person : completion) {
        list[person]--;
        if (list[person] == 0) {
            list.erase(person);
        }
    }
    // 해시에 남은 마지막 선수 반환
    string uncompleted = list.begin()->first;
    return uncompleted;
}

/**
 *  (1-2) unordered_multiset 사용
 */
string solution(vector<string> participant, vector<string> completion) {
    // 선수들을 해시 테이블에 저장
    unordered_multiset<string> players;
    for (string player : participant) {
        players.insert(player);
    }
    // 완주한 선수들은 해시테이블에서 제외
    for (string player : completion) {
        auto it = players.find(player);
        players.erase(it);
    }
    // 마지막 남은 선수 반환
    return *players.begin();
}

/**
 *  (2) 정렬 후 비교
 */
string solution(vector<string> participant, vector<string> completion) {
    // 선수 배열과 완주 선수 배열을 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 선수 배열과 완수 선수 배열 비교
    int size = completion.size();
    for (int i = 0; i < size; i++) {
        // 일치하지 않는다면, 해당 선수가 완주하지 못한 선수
        if (completion[i] != participant[i])
            return participant[i];
    }
    // 마지막 선수가 완주하지 못한 선수
    return participant[size];
}