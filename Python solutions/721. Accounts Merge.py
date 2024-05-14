from typing import List

"""
REVISIT LATER
"""

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        nameAccountMap = {}
        emailAccountMap = {}
        visited = [False] * len(accounts)

        for i, account in enumerate(accounts):
            for j in range(1, len(account)):
                email = account[j]
                if email not in emailAccountMap:
                    emailAccountMap[email] = []
                emailAccountMap[email].append(i)

        def dfs(i, emails) -> None:
            # Base Case -- Check email
            if visited[i]: return

            visited[i] = True
            # Recursive Case
            

            return

        print(nameAccountMap)
        print(emailAccountMap)

        return []

"""
    Graph question
    Based on the position in the accounts list, assign each email an "account number"
    Then for each email, map a list of account numbers that's associated with the email

    If a cycle is detected for any of the emails, that must been they're owned by the same person
    Otherwise those emails belong to two different people with the same name

"""

accounts1 = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
ans1 = [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
assert Solution().accountsMerge(accounts1) == ans1, "Test failed!"

accounts2 = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
ans2 = [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
assert Solution().accountsMerge(accounts2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")