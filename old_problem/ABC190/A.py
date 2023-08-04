A, B, C = map(int, input().split())


def main():
    if A == B:
        print("Aoki" if C == 0 else "Takahashi")
        return

    print("Aoki" if A < B else "Takahashi")


main()
