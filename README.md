# AoCS
Homework for HSE course "Architecture of computer systems"

* Задача 1:

* Решение:
'''
int main() {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz", s;
    std::cin >> s;

    for (int i = 0; i < alphabet.size(); ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < s.size(); ++j) {
            std::cout << alphabet[(s[j] - i) % 26];
        }
        std::cout << std::endl;
    }
}
'''
* Вывод:
'''
0: gpetarvkqp
1: fodszqujpo
2: encryption
3: dmbqxoshnm
4: clapwnrgml
5: bkzovmqflk
6: ajynulpekj
7: zixmtkodji
8: yhwlsjncih
9: xgvkrimbhg
10: wfujqhlagf
11: vetipgkzfe
12: udshofjyed
13: tcrgneixdc
14: sbqfmdhwcb
15: rapelcgvba
16: qzodkbfuaz
17: pyncjaetzy
18: oxmbizdsyx
19: nwlahycrxw
20: mvkzgxbqwv
21: lujyfwapvu
22: ktixevzout
23: jshwduynts
24: irgvctxmsr
25: hqfubswlrq
'''
* Вывод:
Изначальный сдвиг - 2 символа.
Закодированное слово - encryption
