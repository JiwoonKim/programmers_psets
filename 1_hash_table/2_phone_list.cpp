/**
 *  [문제] 전화번호 목록
 *  : 전화번호부에 적힌 전화번호를 담은 배열 phone_book이 주어질 때, 
 *    어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 반환하기
 *    (Reference: https://programmers.co.kr/learn/courses/30/lessons/42577)
 * 
 * 
 *  [해결 방법]
 * 
 *    (1) 브루트 포스: O(n^2) time, O(1) extra space
 *        -> 각 번호마다 다른 번호들의 접두어인지 체크
 * 
 *    (2) Trie 사용: O(n) time, O(n) extra space
 *        -> 체크 시간을 줄이기 위해, 각 전화번호를 Trie 자료구조에 저장하여 비교하는 방식
 *           (단순히 몇 번째 자리에 어떤 숫자들이 존재한다가 아니라, 반드시 이어지는 경로 또는 관계까지 저장해야 함)
 *           -> 각 전화번호들을 Trie에 저장해나가면서 
 *              혹시 해당 전화번호가 이미 저장된 다른 전화번호의 접두어인지 체크
 *              -> 접두어라면, 바로 false 반환
 *           -> 모든 전화번호들을 저장하고 체크했음에도 접두어인 경우가 단 하나도 없다면, true 반환
 *          
 *        cf) 전화번호들을 긴 순서대로 정렬한 후면, 굳이 isEnd를 저장 및 비교할 필요가 없어진다
 *            대신, 그럴 경우 시간 복잡도가 효율성이 떨어지기 때문에 차라리 (3)해법이 낫다
 * 
 *    (3) 정렬 후 비교: O(n logn) time, O(1) extra space
 *        -> 
 * 
 * 
 *  [What I learned]
 * 
 *     ** Trie 자료구조
 * 
 * 
 *     ** 정렬 활용하기
 * 
 * 
 *     ** 테스트 케이스 직접 만들기
 *        - ex. ["31", "111", "222", "321"] -> true
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (2) Trie 사용
 */
bool solution(vector<string> phone_book) {
    
    // 각 전화번호를 Trie에 저장해가면 접두어 체크
    TrieNode* head = new TrieNode();
    for (string phone_num : phone_book) {
        TrieNode* current = head;
        bool prefix_flag = true;
        
        // 전화번호의 각 자리 번호를 등록하며 경로 이동
        for (char char_num : phone_num) {
            int num = char_num - '0';
            
            // 경로가 존재하지 않는다면, 경로 추가
            if (!current->children[num]) {
                current->children[num] = new TrieNode();
                prefix_flag = false;
            }
            // 경로추적 포인터 업데이트
            current = current->children[num];
        }
        // 번호가 접두어라면,
        if (prefix_flag) return false;
    }
    // 접두어가 단 하나도 없다면,
    return true;
}

/**
 *  트라이 노드 자료구조 정의
 */
class TrieNode {
public:
    TrieNode* children[10];
};

/**
 *  (3) 정렬 후 비교
 */
bool solution(vector<string> phone_book) {
    // 문자열 오름차순으로 정렬
    sort(phone_book.begin(), phone_book.end());
    
    // 순서대로 두 개씩 비교하기
    for (int i = 0, n = phone_book.size(); i < n - 1; i++) {
        string prefix = phone_book[i];

        // 문자열이 바로 뒤 문자열의 접두사이면,
        if (phone_book[i+1].substr(0, prefix.length()) == prefix) {
            return false;
        }
    }
    // 접두사가 하나도 존재하지 않는다면,
    return true;
}