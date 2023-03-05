#include <stdio.h>

int main() {
	char s[1000001];
	scanf("%[^\n]", &s);

	int cnt = 0;
	if (s[0] != ' ') ++cnt;

	int i = 0;
	while (s[i]) {
		if (s[i] == ' ') ++cnt;
		++i;
	}

	if (s[i - 1] == ' ') --cnt;

	printf("%d\n", cnt);
	return 0;
}