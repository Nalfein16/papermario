#include "common.h"
#include "animation_script.h"

extern Gfx Entity_MunchlesiaReset_Render[];
extern Vtx D_0A000000_E6E660[];

AnimScript Entity_MunchlesiaReset_AnimationIdle = {
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_Restart
    as_End
};

AnimScript Entity_MunchlesiaReset_AnimationReset = {
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 0, 2, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 0, 4, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_SetRotation(6, 0.0, 0.0, 0.0)
    as_SetPos(6, 0, 5, 0)
    as_SetScale(6, 1.0, 1.0, 1.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetPos(7, 0, 4, 0)
    as_SetScale(7, 1.0, 1.0, 1.0)
    as_Loop
    as_SetRotation(8, 0.0, 0.0, 0.0)
    as_SetPos(8, 0, 4, 0)
    as_SetScale(8, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Restart
    as_End
};

StaticAnimatorNode Entity_MunchlesiaReset_Node8 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .pos = { 0.0f, 4.0f, 0.0f },
    .sibling = ANIM_NULL,
    .child = ANIM_NULL,
    .vertexStartOffset = 399 * 6,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node7 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .pos = { 0.0f, 4.0f, 0.0f },
    .sibling = &Entity_MunchlesiaReset_Node8,
    .child = ANIM_NULL,
    .vertexStartOffset = 399 * 5,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node6 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .pos = { 0.0f, 5.0f, 0.0f },
    .sibling = &Entity_MunchlesiaReset_Node7,
    .child = ANIM_NULL,
    .vertexStartOffset = 399 * 4,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node5 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .pos = { 0.0f, 4.0f, 0.0f },
    .sibling = &Entity_MunchlesiaReset_Node6,
    .child = ANIM_NULL,
    .vertexStartOffset = 399 * 3,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node4 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .pos = { 0.0f, 2.0f, 0.0f },
    .sibling = &Entity_MunchlesiaReset_Node5,
    .child = ANIM_NULL,
    .vertexStartOffset = 399 * 2,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node3 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .sibling = &Entity_MunchlesiaReset_Node4,
    .child = ANIM_NULL,
    .vertexStartOffset = 399,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node2 = {
    .displayList = Entity_MunchlesiaReset_Render,
    .sibling = &Entity_MunchlesiaReset_Node3,
    .child = ANIM_NULL,
    .vtxList = D_0A000000_E6E660,
};

StaticAnimatorNode Entity_MunchlesiaReset_Node1 = {
    .displayList = ANIM_NULL,
    .sibling = ANIM_NULL,
    .child = &Entity_MunchlesiaReset_Node2,
    .vertexStartOffset = (s32)ANIM_NULL,
    .vtxList = ANIM_NULL,
};

StaticAnimatorNode* Entity_MunchlesiaReset_Mesh[] = {
    &Entity_MunchlesiaReset_Node1,
    &Entity_MunchlesiaReset_Node2,
    &Entity_MunchlesiaReset_Node3,
    &Entity_MunchlesiaReset_Node4,
    &Entity_MunchlesiaReset_Node5,
    &Entity_MunchlesiaReset_Node6,
    &Entity_MunchlesiaReset_Node7,
    &Entity_MunchlesiaReset_Node8,
    ANIM_NULL,
};
