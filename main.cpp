#include <iostream>
using namespace std;

char oper[4097], input[4097];
int stack[4097], arr[100001], loop[4097];
int Sm, Sc, Si;

void PairLoop()
{
    int top = -1;
    for (int i = 0; i < Sc; i++)
    {
        if (oper[i] == '[')
        {
            stack[++top] = i;
        }
        else if (oper[i] == ']')
        {
            stack[++top] = i;
            loop[stack[top]] = stack[top - 1];
            loop[stack[top - 1]] = i;
            top -= 2;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> Sm >> Sc >> Si;
        for (int i = 0; i < Sm; i++)
            arr[i] = 0;
        for (int j = 0; j < Sc; j++)
            loop[j] = 0;

        cin >> oper;
        cin >> input;
        PairLoop();

        int index = 0, oper_index = 0, input_index = 0, max_oper_index = 0;
        bool flag = false;

        for (int i = 1; i <= 50000000; i++)
        {
            if (oper_index >= Sc)
            {
                cout << "Terminates" << "\n";
                flag = true;
                break;
            }
            if (oper[oper_index] == '-')
            {
                arr[index] = (arr[index] - 1) < 0 ? 255 : arr[index] - 1;
            }
            else if (oper[oper_index] == '+')
            {
                arr[index] = (arr[index] + 1) % 256;
            }
            else if (oper[oper_index] == '<')
            {
                index = index - 1 < 0 ? Sm - 1 : index - 1;
            }
            else if (oper[oper_index] == '>')
            {
                index = (index + 1) % Sm;
            }
            else if (oper[oper_index] == '[')
            {
                if (arr[index] == 0)
                {
                    oper_index = loop[oper_index];
                }
            }
            else if (oper[oper_index] == ']')
            {
                if (arr[index] != 0)
                {
                    oper_index = loop[oper_index];
                }
            }
            else if (oper[oper_index] == ',')
            {
                int c = input_index >= Si ? 255 : (int)input[input_index];
                arr[index] = c;
                input_index = input_index >= Si ? input_index : input_index + 1;
            }
            oper_index++;
            max_oper_index = oper_index > max_oper_index ? oper_index : max_oper_index;
        }
        if (!flag)
        {
            cout << "Loops " << loop[max_oper_index] << " " << max_oper_index << "\n";
        }
    }
}
