N, M = map(int, input().split())

# たぶん、x, y は順番固定（x < y）するとよい
# 3 1で並んでいても、1 3 が並んでいたと解釈する.
# 小さい方の配列でindexがキーの辞書を作るとよいかな。

IS_DISCORD = True

members = {
    n: { i: IS_DISCORD for i in range(n + 1, N + 1) } for n in range(1, N + 1)
}
# Falseのとき、そのメンバーとは不仲の可能性が残っているとする。

for m in range(M):
    a_list = list(map(int, input().split()))
    for i in range(len(a_list) - 1):
        # メンバー a に対して、右隣のメンバーを非不仲判定する
        a = a_list[i]
        b = a_list[i + 1]

        if a > b:
            a, b = b, a  # 順番は小さいほうを前にする

        members[a][b] = not IS_DISCORD

discord_count = 0

for partners in members.values():
    for is_discord in partners.values():
        discord_count += int(is_discord == IS_DISCORD)

print(discord_count)