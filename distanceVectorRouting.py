# Write a program for distance vector routing
import collections
INFINITY = float('inf')
class Router:
    def __init__(self, name):
        self.name = name
        self.routing_table = {name: (name, 0)}
        self.neighbors = {}
    def add_neighbor(self, neighbor, cost):
        self.neighbors[neighbor] = cost
        self.routing_table[neighbor.name] = (neighbor.name, cost)
    def update_routing_table(self, neighbor, neighbor_table):
        table_updated = False
        cost_to_neighbor = self.neighbors[neighbor]
        for dest, (_, cost_from_neighbor) in neighbor_table.items():
            new_cost = cost_to_neighbor + cost_from_neighbor
            if dest not in self.routing_table or new_cost < self.routing_table[dest][1]:
                self.routing_table[dest] = (neighbor.name, new_cost)
                table_updated = True
        return table_updated
    def print_routing_table(self):
        print(f"--- Routing Table for {self.name} ---")
        print("Dest | Next Hop | Cost")
        print("------------------------")
        sorted_table = sorted(self.routing_table.items())
        for dest, (next_hop, cost) in sorted_table:
            print(f"{dest:^4} | {next_hop:^8} | {cost:^4}")
        print("\n")
def simulate_network(routers):
    round_num = 1
    while True:
        print(f"--- ROUND {round_num} ---\n")
        any_table_updated = False
        current_tables = {router.name: router.routing_table.copy() for router in routers}
        for router in routers:
            for neighbor in router.neighbors:
                
                if router.update_routing_table(neighbor, current_tables[neighbor.name]):
                    any_table_updated = True
        for router in routers:
            router.print_routing_table()
        if not any_table_updated:
            print("Network has converged. No more updates.")
            break
        round_num += 1
if __name__ == '__main__':
    router_a = Router('A')
    router_b = Router('B')
    router_c = Router('C')
    router_d = Router('D')
    router_e = Router('E')
    router_a.add_neighbor(router_b, 1)
    router_a.add_neighbor(router_d, 3)
    router_a.add_neighbor(router_e, 2)
    router_b.add_neighbor(router_a, 1)
    router_b.add_neighbor(router_c, 2)
    router_b.add_neighbor(router_e, 1)
    router_c.add_neighbor(router_b, 2)
    router_c.add_neighbor(router_e, 1)
    router_d.add_neighbor(router_a, 3)
    router_d.add_neighbor(router_e, 1)
    router_e.add_neighbor(router_a, 2)
    router_e.add_neighbor(router_b, 1)
    router_e.add_neighbor(router_c, 1)
    router_e.add_neighbor(router_d, 1)
    network_routers = [router_a, router_b, router_c, router_d, router_e]
    print("--- INITIAL ROUTING TABLES ---\n")
    for r in network_routers:
        r.print_routing_table()
    simulate_network(network_routers)