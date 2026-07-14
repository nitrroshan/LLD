package main

// NumberExpr is a Concrete Element — a literal number.
type NumberExpr struct {
	value float64
}

func NewNumberExpr(value float64) *NumberExpr {
	return &NumberExpr{value: value}
}

func (n *NumberExpr) Value() float64 { return n.value }

func (n *NumberExpr) Accept(visitor Visitor) {
	visitor.VisitNumber(n) // double dispatch
}
