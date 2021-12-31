#include <stdio.h>
#include "ALGraph.h"

int main(void) {
	ALGraph graph; // �� �������� �޸� ������ �Ҵ�˴ϴ�.
	GraphInit(&graph, 5); // A ~ E

	AddEdge(&graph, A, B); // ���ڴ� ���ڷ� �ؼ��˴ϴ�. A->B
	AddEdge(&graph, A, D); // A->D
	AddEdge(&graph, B, C); // B->C ..
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph); // �׷����� ��� ���� ������ ����մϴ�.
	GraphDestroy(&graph); // �׷����� ���ҽ� �Ҹ� 

	return 0;
}
