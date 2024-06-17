import request from '@/apis/request';

// 查询消息列表
export async function listMessage(query) {
    try {
        const response = await request({
            url: '/system/message/list',
            method: 'get',
            params: query
        });
        return response;
    } catch (error) {
        console.error('获取消息列表失败:', error);
        throw error;
    }
}

// 查询消息详细
export async function getMessage(messageId) {
    try {
        const response = await request({
            url: `/system/message/${messageId}`,
            method: 'get'
        });
        return response;
    } catch (error) {
        console.error('获取消息详情失败:', error);
        throw error;
    }
}

// 新增消息
export async function addMessage(data) {
    try {
        const response = await request({
            url: '/system/message',
            method: 'post',
            data: data
        });
        return response;
    } catch (error) {
        console.error('新增消息失败:', error);
        throw error;
    }
}

// 修改消息
export async function updateMessage(data) {
    try {
        const response = await request({
            url: '/system/message',
            method: 'put',
            data: data
        });
        return response;
    } catch (error) {
        console.error('修改消息失败:', error);
        throw error;
    }
}

// 删除消息
export async function delMessage(messageId) {
    try {
        const response = await request({
            url: `/system/message/${messageId}`,
            method: 'delete'
        });
        return response;
    } catch (error) {
        console.error('删除消息失败:', error);
        throw error;
    }
}
