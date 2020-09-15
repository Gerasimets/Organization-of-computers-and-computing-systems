#include <iostream>

using namespace std;

int main()
{
    /*� ������� �� 10 ����� �������� ��� ������������� �������� �� ������������ ������� �������*/
    int MASS[10];
    int* mass = MASS;

    __asm
    {
        mov esi, mass // � esi ������ ������ ������� MASS
        mov eax, 10 // ��� ��� � ������� 10 ���������
        mov edx, eax // ���������� 10 � edx
        xor ecx, ecx // �������� �������
        xor eax, eax // � eax
        mov ebx, -5
        
        start : // ���������� �������� �������� �������
        cmp ecx, edx // ���������� ������� � ����������� ���������

        je End // ���� ��� �����, ������ �� ������ ��� ��������

        mov[esi], ebx // ���� ���, �� ������ ����� ������� �� �������
        inc ebx
        add esi, 4 // ��� ��� � ��� int, ����������� ������ �� 4
        inc ecx // ������� ��������, ������� �����������
        jmp start // ������������ ����� ��������� ��������� �������

        End : // ��� �������� ���������
    }

    for (int i = 0; i < 10; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;

    __asm
    {
        mov esi, mass
        add esi, 40

        xor ecx, ecx

        sub esi, 4

        mov ebx, [esi]

        start1:
        inc ecx
        cmp ebx, [esi]
        JNL end1
        JNGE new_max

        new_max :
        mov ebx, [esi]
        jmp end1

        end1 :
        sub esi, 4
        cmp ecx, 10
        je end2
        jmp start1

        end2 :
        add esi, 4
        xor ecx, ecx

        start2:
        inc ecx
        cmp [esi], 0
        JNGE divis
        jmp end3

        divis:
        xor edx, edx
        mov eax, [esi]
        cdq // ��������� ������� (EAX) �� EDX:EAX
        idiv ebx
        mov [esi], edx

        end3:
        add esi, 4
        cmp ecx, 10
        JNE start2
    }

    for (int i = 0; i < 10; i++)
    {
        cout << mass[i] << " ";
    }

    return 0;
}