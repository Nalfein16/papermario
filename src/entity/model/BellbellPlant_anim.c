#include "common.h"
#include "animation_script.h"

extern Gfx Entity_BellbellPlant_RenderNode1[];
extern Gfx Entity_BellbellPlant_RenderNode2[];
extern Gfx Entity_BellbellPlant_RenderNode3[];
extern Gfx Entity_BellbellPlant_RenderNode4[];
extern Gfx Entity_BellbellPlant_RenderNode5[];

StaticAnimatorNode Entity_BellbellPlant_Node5 = {
    .displayList = Entity_BellbellPlant_RenderNode5,
    .rot = { -1092, 0, 0 },
    .sibling = ANIM_NULL,
    .child = ANIM_NULL,
};

StaticAnimatorNode Entity_BellbellPlant_Node4 = {
    .displayList = Entity_BellbellPlant_RenderNode4,
    .rot = { -2455, 0, 0 },
    .pos = { 15.0f, 39.0f, 0.0f },
    .sibling = ANIM_NULL,
    .child = &Entity_BellbellPlant_Node5,
};

StaticAnimatorNode Entity_BellbellPlant_Node3 = {
    .displayList = Entity_BellbellPlant_RenderNode3,
    .rot = { -1092, 0, 0 },
    .sibling = ANIM_NULL,
    .child = ANIM_NULL,
};

StaticAnimatorNode Entity_BellbellPlant_Node2 = {
    .displayList = Entity_BellbellPlant_RenderNode2,
    .rot = { -2455, 0, 0 },
    .pos = { -15.0f, 30.0f, 0.0f },
    .sibling = &Entity_BellbellPlant_Node4,
    .child = &Entity_BellbellPlant_Node3,
};

StaticAnimatorNode Entity_BellbellPlant_Node1 = {
    .displayList = Entity_BellbellPlant_RenderNode1,
    .rot = { -2457, 0, 0 },
    .sibling = ANIM_NULL,
    .child = &Entity_BellbellPlant_Node2,
};

StaticAnimatorNode* Entity_BellbellPlant_Mesh[] = {
    &Entity_BellbellPlant_Node1,
    &Entity_BellbellPlant_Node2,
    &Entity_BellbellPlant_Node3,
    &Entity_BellbellPlant_Node4,
    &Entity_BellbellPlant_Node5,
    ANIM_NULL,
};

AnimScript Entity_BellbellPlant_AnimationUse = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, -15, 30, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 15, 39, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 0, 0, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_SetRotation(1, -13.495, 0.0, 0.0)
    as_SetRotation(2, -13.485, 0.0, 0.0)
    as_SetRotation(3, -6.0, 0.0, 0.0)
    as_SetRotation(4, -13.485, 0.0, 0.0)
    as_SetRotation(5, -6.0, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -24.995, 0.0, 0.0)
    as_SetRotation(2, -24.995, 0.0, 0.0)
    as_SetRotation(3, -10.0, 0.0, 0.0)
    as_SetRotation(4, -24.995, 0.0, 0.0)
    as_SetRotation(5, -10.0, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -11.87, 0.0, 0.0)
    as_SetRotation(2, 11.87, 0.0, 0.0)
    as_SetRotation(3, -0.43, 0.0, 0.0)
    as_SetRotation(4, 11.87, 0.0, 0.0)
    as_SetRotation(5, -0.485, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 8.585, 0.0, 0.0)
    as_SetRotation(2, 13.79, 0.0, 0.0)
    as_SetRotation(3, 13.135, 0.0, 0.0)
    as_SetRotation(4, 12.595, 0.0, 0.0)
    as_SetRotation(5, 13.025, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 19.995, 0.0, 0.0)
    as_SetRotation(2, 5.0, 0.0, 0.0)
    as_SetRotation(3, 19.995, 0.0, 0.0)
    as_SetRotation(4, 5.0, 0.0, 0.0)
    as_SetRotation(5, 19.995, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 15.54, 0.0, 0.0)
    as_SetRotation(2, -18.375, 0.0, 0.0)
    as_SetRotation(3, 12.115, 0.0, 0.0)
    as_SetRotation(4, -5.155, 0.0, 0.0)
    as_SetRotation(5, 15.645, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 3.77, 0.0, 0.0)
    as_SetRotation(2, -33.77, 0.0, 0.0)
    as_SetRotation(3, -2.47, 0.0, 0.0)
    as_SetRotation(4, -16.74, 0.0, 0.0)
    as_SetRotation(5, 5.81, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -8.635, 0.0, 0.0)
    as_SetRotation(2, -21.035, 0.0, 0.0)
    as_SetRotation(3, -10.32, 0.0, 0.0)
    as_SetRotation(4, -21.36, 0.0, 0.0)
    as_SetRotation(5, -4.1, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -14.995, 0.0, 0.0)
    as_SetRotation(2, 1.135, 0.0, 0.0)
    as_SetRotation(3, -2.465, 0.0, 0.0)
    as_SetRotation(4, -16.295, 0.0, 0.0)
    as_SetRotation(5, -8.7, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -13.215, 0.0, 0.0)
    as_SetRotation(2, 22.38, 0.0, 0.0)
    as_SetRotation(3, 12.12, 0.0, 0.0)
    as_SetRotation(4, -6.555, 0.0, 0.0)
    as_SetRotation(5, -5.945, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -7.325, 0.0, 0.0)
    as_SetRotation(2, 32.325, 0.0, 0.0)
    as_SetRotation(3, 19.995, 0.0, 0.0)
    as_SetRotation(4, 4.605, 0.0, 0.0)
    as_SetRotation(5, 0.84, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.17, 0.0, 0.0)
    as_SetRotation(2, 26.94, 0.0, 0.0)
    as_SetRotation(3, 16.905, 0.0, 0.0)
    as_SetRotation(4, 13.94, 0.0, 0.0)
    as_SetRotation(5, 8.985, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 6.785, 0.0, 0.0)
    as_SetRotation(2, 12.825, 0.0, 0.0)
    as_SetRotation(3, 9.465, 0.0, 0.0)
    as_SetRotation(4, 18.21, 0.0, 0.0)
    as_SetRotation(5, 15.815, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 10.0, 0.0, 0.0)
    as_SetRotation(2, -4.45, 0.0, 0.0)
    as_SetRotation(3, 0.575, 0.0, 0.0)
    as_SetRotation(4, 16.35, 0.0, 0.0)
    as_SetRotation(5, 18.65, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 9.23, 0.0, 0.0)
    as_SetRotation(2, -19.325, 0.0, 0.0)
    as_SetRotation(3, -6.87, 0.0, 0.0)
    as_SetRotation(4, 10.645, 0.0, 0.0)
    as_SetRotation(5, 16.53, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 6.235, 0.0, 0.0)
    as_SetRotation(2, -26.235, 0.0, 0.0)
    as_SetRotation(3, -10.0, 0.0, 0.0)
    as_SetRotation(4, 2.935, 0.0, 0.0)
    as_SetRotation(5, 11.32, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 2.05, 0.0, 0.0)
    as_SetRotation(2, -23.645, 0.0, 0.0)
    as_SetRotation(3, -7.725, 0.0, 0.0)
    as_SetRotation(4, -4.975, 0.0, 0.0)
    as_SetRotation(5, 4.575, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -2.315, 0.0, 0.0)
    as_SetRotation(2, -15.465, 0.0, 0.0)
    as_SetRotation(3, -2.05, 0.0, 0.0)
    as_SetRotation(4, -11.28, 0.0, 0.0)
    as_SetRotation(5, -2.14, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -5.84, 0.0, 0.0)
    as_SetRotation(2, -4.335, 0.0, 0.0)
    as_SetRotation(3, 5.285, 0.0, 0.0)
    as_SetRotation(4, -14.155, 0.0, 0.0)
    as_SetRotation(5, -7.28, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -7.5, 0.0, 0.0)
    as_SetRotation(2, 7.125, 0.0, 0.0)
    as_SetRotation(3, 12.565, 0.0, 0.0)
    as_SetRotation(4, -13.215, 0.0, 0.0)
    as_SetRotation(5, -9.28, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -7.13, 0.0, 0.0)
    as_SetRotation(2, 16.295, 0.0, 0.0)
    as_SetRotation(3, 18.04, 0.0, 0.0)
    as_SetRotation(4, -9.885, 0.0, 0.0)
    as_SetRotation(5, -7.585, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -5.55, 0.0, 0.0)
    as_SetRotation(2, 20.545, 0.0, 0.0)
    as_SetRotation(3, 19.995, 0.0, 0.0)
    as_SetRotation(4, -5.07, 0.0, 0.0)
    as_SetRotation(5, -3.365, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -3.195, 0.0, 0.0)
    as_SetRotation(2, 19.375, 0.0, 0.0)
    as_SetRotation(3, 17.835, 0.0, 0.0)
    as_SetRotation(4, 0.325, 0.0, 0.0)
    as_SetRotation(5, 2.345, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -0.525, 0.0, 0.0)
    as_SetRotation(2, 14.86, 0.0, 0.0)
    as_SetRotation(3, 12.87, 0.0, 0.0)
    as_SetRotation(4, 5.405, 0.0, 0.0)
    as_SetRotation(5, 8.55, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 2.02, 0.0, 0.0)
    as_SetRotation(2, 8.24, 0.0, 0.0)
    as_SetRotation(3, 6.215, 0.0, 0.0)
    as_SetRotation(4, 9.255, 0.0, 0.0)
    as_SetRotation(5, 14.21, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 4.01, 0.0, 0.0)
    as_SetRotation(2, 0.765, 0.0, 0.0)
    as_SetRotation(3, -1.015, 0.0, 0.0)
    as_SetRotation(4, 10.98, 0.0, 0.0)
    as_SetRotation(5, 18.315, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 5.0, 0.0, 0.0)
    as_SetRotation(2, -6.31, 0.0, 0.0)
    as_SetRotation(3, -7.705, 0.0, 0.0)
    as_SetRotation(4, 10.15, 0.0, 0.0)
    as_SetRotation(5, 19.84, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 4.96, 0.0, 0.0)
    as_SetRotation(2, -11.755, 0.0, 0.0)
    as_SetRotation(3, -12.74, 0.0, 0.0)
    as_SetRotation(4, 7.425, 0.0, 0.0)
    as_SetRotation(5, 18.49, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 4.31, 0.0, 0.0)
    as_SetRotation(2, -14.31, 0.0, 0.0)
    as_SetRotation(3, -14.995, 0.0, 0.0)
    as_SetRotation(4, 3.54, 0.0, 0.0)
    as_SetRotation(5, 15.09, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 3.22, 0.0, 0.0)
    as_SetRotation(2, -13.855, 0.0, 0.0)
    as_SetRotation(3, -14.23, 0.0, 0.0)
    as_SetRotation(4, -0.78, 0.0, 0.0)
    as_SetRotation(5, 10.31, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 1.875, 0.0, 0.0)
    as_SetRotation(2, -11.475, 0.0, 0.0)
    as_SetRotation(3, -11.365, 0.0, 0.0)
    as_SetRotation(4, -4.825, 0.0, 0.0)
    as_SetRotation(5, 4.82, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.45, 0.0, 0.0)
    as_SetRotation(2, -7.77, 0.0, 0.0)
    as_SetRotation(3, -7.075, 0.0, 0.0)
    as_SetRotation(4, -7.845, 0.0, 0.0)
    as_SetRotation(5, -0.71, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -0.87, 0.0, 0.0)
    as_SetRotation(2, -3.32, 0.0, 0.0)
    as_SetRotation(3, -2.025, 0.0, 0.0)
    as_SetRotation(4, -9.125, 0.0, 0.0)
    as_SetRotation(5, -5.61, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -1.91, 0.0, 0.0)
    as_SetRotation(2, 1.275, 0.0, 0.0)
    as_SetRotation(3, 3.12, 0.0, 0.0)
    as_SetRotation(4, -8.52, 0.0, 0.0)
    as_SetRotation(5, -9.21, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -2.5, 0.0, 0.0)
    as_SetRotation(2, 5.435, 0.0, 0.0)
    as_SetRotation(3, 7.7, 0.0, 0.0)
    as_SetRotation(4, -6.645, 0.0, 0.0)
    as_SetRotation(5, -10.85, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -2.655, 0.0, 0.0)
    as_SetRotation(2, 8.565, 0.0, 0.0)
    as_SetRotation(3, 11.045, 0.0, 0.0)
    as_SetRotation(4, -3.91, 0.0, 0.0)
    as_SetRotation(5, -10.19, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -2.57, 0.0, 0.0)
    as_SetRotation(2, 10.075, 0.0, 0.0)
    as_SetRotation(3, 12.495, 0.0, 0.0)
    as_SetRotation(4, -0.715, 0.0, 0.0)
    as_SetRotation(5, -7.745, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -2.315, 0.0, 0.0)
    as_SetRotation(2, 10.095, 0.0, 0.0)
    as_SetRotation(3, 12.145, 0.0, 0.0)
    as_SetRotation(4, 2.52, 0.0, 0.0)
    as_SetRotation(5, -4.07, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -1.925, 0.0, 0.0)
    as_SetRotation(2, 9.28, 0.0, 0.0)
    as_SetRotation(3, 10.695, 0.0, 0.0)
    as_SetRotation(4, 5.405, 0.0, 0.0)
    as_SetRotation(5, 0.265, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -1.46, 0.0, 0.0)
    as_SetRotation(2, 7.805, 0.0, 0.0)
    as_SetRotation(3, 8.405, 0.0, 0.0)
    as_SetRotation(4, 7.53, 0.0, 0.0)
    as_SetRotation(5, 4.7, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -0.98, 0.0, 0.0)
    as_SetRotation(2, 5.865, 0.0, 0.0)
    as_SetRotation(3, 5.52, 0.0, 0.0)
    as_SetRotation(4, 8.48, 0.0, 0.0)
    as_SetRotation(5, 8.685, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -0.54, 0.0, 0.0)
    as_SetRotation(2, 3.64, 0.0, 0.0)
    as_SetRotation(3, 2.305, 0.0, 0.0)
    as_SetRotation(4, 8.24, 0.0, 0.0)
    as_SetRotation(5, 11.635, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, -0.19, 0.0, 0.0)
    as_SetRotation(2, 1.32, 0.0, 0.0)
    as_SetRotation(3, -0.995, 0.0, 0.0)
    as_SetRotation(4, 7.19, 0.0, 0.0)
    as_SetRotation(5, 13.005, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetRotation(2, -0.905, 0.0, 0.0)
    as_SetRotation(3, -4.125, 0.0, 0.0)
    as_SetRotation(4, 5.55, 0.0, 0.0)
    as_SetRotation(5, 12.62, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.09, 0.0, 0.0)
    as_SetRotation(2, -2.86, 0.0, 0.0)
    as_SetRotation(3, -6.84, 0.0, 0.0)
    as_SetRotation(4, 3.51, 0.0, 0.0)
    as_SetRotation(5, 10.965, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.155, 0.0, 0.0)
    as_SetRotation(2, -4.35, 0.0, 0.0)
    as_SetRotation(3, -8.885, 0.0, 0.0)
    as_SetRotation(4, 1.295, 0.0, 0.0)
    as_SetRotation(5, 8.405, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.2, 0.0, 0.0)
    as_SetRotation(2, -5.195, 0.0, 0.0)
    as_SetRotation(3, -10.0, 0.0, 0.0)
    as_SetRotation(4, -0.885, 0.0, 0.0)
    as_SetRotation(5, 5.325, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.22, 0.0, 0.0)
    as_SetRotation(2, -5.48, 0.0, 0.0)
    as_SetRotation(3, -10.28, 0.0, 0.0)
    as_SetRotation(4, -2.84, 0.0, 0.0)
    as_SetRotation(5, 2.095, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.23, 0.0, 0.0)
    as_SetRotation(2, -5.45, 0.0, 0.0)
    as_SetRotation(3, -10.045, 0.0, 0.0)
    as_SetRotation(4, -4.355, 0.0, 0.0)
    as_SetRotation(5, -0.905, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.22, 0.0, 0.0)
    as_SetRotation(2, -5.16, 0.0, 0.0)
    as_SetRotation(3, -9.395, 0.0, 0.0)
    as_SetRotation(4, -5.225, 0.0, 0.0)
    as_SetRotation(5, -3.305, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.205, 0.0, 0.0)
    as_SetRotation(2, -4.665, 0.0, 0.0)
    as_SetRotation(3, -8.415, 0.0, 0.0)
    as_SetRotation(4, -5.465, 0.0, 0.0)
    as_SetRotation(5, -4.735, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.18, 0.0, 0.0)
    as_SetRotation(2, -4.02, 0.0, 0.0)
    as_SetRotation(3, -7.2, 0.0, 0.0)
    as_SetRotation(4, -5.31, 0.0, 0.0)
    as_SetRotation(5, -5.215, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.15, 0.0, 0.0)
    as_SetRotation(2, -3.285, 0.0, 0.0)
    as_SetRotation(3, -5.85, 0.0, 0.0)
    as_SetRotation(4, -4.845, 0.0, 0.0)
    as_SetRotation(5, -5.11, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.115, 0.0, 0.0)
    as_SetRotation(2, -2.51, 0.0, 0.0)
    as_SetRotation(3, -4.45, 0.0, 0.0)
    as_SetRotation(4, -4.14, 0.0, 0.0)
    as_SetRotation(5, -4.56, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.075, 0.0, 0.0)
    as_SetRotation(2, -1.75, 0.0, 0.0)
    as_SetRotation(3, -3.095, 0.0, 0.0)
    as_SetRotation(4, -3.285, 0.0, 0.0)
    as_SetRotation(5, -3.705, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.05, 0.0, 0.0)
    as_SetRotation(2, -1.065, 0.0, 0.0)
    as_SetRotation(3, -1.88, 0.0, 0.0)
    as_SetRotation(4, -2.36, 0.0, 0.0)
    as_SetRotation(5, -2.685, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.02, 0.0, 0.0)
    as_SetRotation(2, -0.51, 0.0, 0.0)
    as_SetRotation(3, -0.895, 0.0, 0.0)
    as_SetRotation(4, -1.45, 0.0, 0.0)
    as_SetRotation(5, -1.635, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.005, 0.0, 0.0)
    as_SetRotation(2, -0.13, 0.0, 0.0)
    as_SetRotation(3, -0.235, 0.0, 0.0)
    as_SetRotation(4, -0.635, 0.0, 0.0)
    as_SetRotation(5, -0.69, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_Wait(1)
    as_Loop
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, -15, 30, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 15, 39, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 0, 0, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};

AnimScript Entity_BellbellPlant_AnimationIdle = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, -15, 30, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 15, 39, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 0, 0, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};
