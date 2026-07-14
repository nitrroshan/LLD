package main

import "fmt"

// Approver is the Handler interface. Each handler can process a request
// or forward it, and can be linked to a successor.
type Approver interface {
	Handle(request PurchaseRequest)
	SetNext(next Approver) Approver
}

// BaseApprover supplies the shared next-reference and forwarding helper.
// Concrete handlers embed it and implement their own Handle.
type BaseApprover struct {
	next Approver
}

func (b *BaseApprover) SetNext(next Approver) Approver {
	b.next = next
	return next
}

// passToNext forwards the request, or reports that no one could approve it.
func (b *BaseApprover) passToNext(request PurchaseRequest) {
	if b.next != nil {
		b.next.Handle(request)
	} else {
		fmt.Printf("  Request for $%.2f (%s) could not be approved by anyone.\n",
			request.Amount, request.Purpose)
	}
}
