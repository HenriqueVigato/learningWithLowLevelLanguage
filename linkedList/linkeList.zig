const std = @import("std");
const allocator = std.mem.Allocator;
const print = std.debug.print;
const expect = std.testing.expect;

const Node = struct {
    value: u16,
    next: ?*Node = null,
    previus: ?*Node = null,

    fn firstbornNode(newNode: u16) Node {
        const node = try allocator.create(Node);
        node.* = Node{
            .value = newNode,
        };
        return node;
    }

    pub fn newNodeStart(newNode: u16, head: ?*Node) Node {
        if (head == null) {
            return firstbornNode(newNode);
        } else {
            const exHead = head;
            const node = try allocator.create(Node);
            node.* = Node{
                .value = newNode,
                .next = exHead,
            };
            exHead.previus = &node;
        }
    }
};

test "testando a criacao do primeiro node" {
    var head: ?*Node = null;
    head = try Node.newNodeStart(1, head);
    try expect(head.value == 1);
    try expect(head.next == null);
}
